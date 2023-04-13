#include <iostream>
#include "game.hpp"
#include <stdexcept>
#include <string>
#include <vector>
#include <random>
#include <algorithm // for the random_shuffle
#include <cstdlib> // for the srand


namespace ariel{
    Game::Game(Player& player1, Player& player2) : p1(player1), p2(player2) , winner(nullptr) , lastTurnStats(""), turn(0), draws(0), player1Wins(0), player2Wins(0)) {
        if (player1.isInTheGame()) {
            throw "player 1 is in the game";
        }
        if (player2.isInTheGame()) {
            throw "player 2 is in the game";
        }

        Vector <Card> deck_of_cards;
        for (int i = 1; i < 14; i++) {
            deck_of_cards.push_back(Card(cardValue)i, Leafs);
        }

        for (int i = 1; i < 14; i++) {
            deck_of_cards.push_back(Card(cardValue)i, Diamonds);
        }

        for (int i = 1; i < 14; i++) {
            deck_of_cards.push_back(Card(cardValue)i, Hearts);
        }

        for (int i = 1; i < 14; i++) {
            deck_of_cards.push_back(Card(cardValue)i, Clovers);
        }


        /* now we need to shuffle the cards */
        // Shuffle the cards
        srand((unsigned int) time(NULL));
        random_shuffle(cards.begin(), cards.end());


        int player = 1;
        while (!cards.empty()) {
            if (player == 1) {
                p1.addCard(cards.back());
                player = 2;
            } else {
                p2.addCard(cards.back());
                player = 1;
            }
            cards.pop_back();
        }
        this->p1.setInGame(true);
        this->p2.setInGame(true);


        void Game::playAll() {
            while (p1.isInGame() && p2.isInGame() && turn < 26) {
                try {
                    playTurn();
                }
                catch (const exception &e) {
                    cerr << e.what() << endl;
                    break;
                }
            }
        }

        void Game::playTurn() {
            if (&p1 == &p2)
                throw error("Cannot play a game with the same player twice!");
            if (!p1.isInGame() || !p2.isInGame())
                throw logic_error("Game is over!");
            if (++turn > 26)
                throw logic_error("The game can't continue with more than 26 turns.");

            int draw_in_this_turn = 0, OnTable = 2;
            lastTurnStats = "turn " + to_string(turn) + ":\n";

            while (true) {
                Card p1Card = p1.playCard();
                Card p2Card = p2.playCard();
                lastTurnStats += p1.getName() + " played " + p1Card.toString() + ", " + p2.getName() + " played " +
                                 p2Card.toString() + ". ";
                if (p1Card == p2Card) {
                    draw_in_this_turn++;
                    lastTurnStats += "draw!\n";
                    if (p1.stacksize() <= 1 || p2.stacksize() <= 1) {
                        while (OnTable > 0) {
                            p1.addCardTaken();
                            p2.addCardTaken();
                            OnTable -= 2;
                        }
                        break;
                    }
                    p1Card = p1.playCard();
                    p2Card = p2.playCard();
                    OnTable += 4;
                    lastTurnStats += p1.getName() + " played " + p1Card.toString() + ", " + p2.getName() + " played " +
                                     p2Card.toString() + ". ";
                }

                if (p1Card > p2Card) {
                    lastTurnStats += p1.getName() + " has won the round.\n";
                    p1.addCardTaken();
                    p1.addCardTaken();
                    OnTable -= 2;
                } else if (p1Card < p2Card) {
                    lastTurnStats += p2.getName() + " has won the round.\n";
                    p2.addCardTaken();
                    p2.addCardTaken();
                    OnTable -= 2;
                } else {
                    lastTurnStats += "draw\n";
                }

                if (!p1.stacksize() || !p2.stacksize()) {
                    p1.setInGame(false);
                    p2.setInGame(false);
                    winner = (p1.cardesTaken() > p2.cardesTaken()) ? &p1 : &p2;
                    break;
                }

                if (OnTable > 26) {
                    throw error("Game cannot continue with more than 26 cards on the table!");
                }
            }

            lastTurnStats += "Draws in this turn: " + to_string(draw_in_this_turn) + "\n\n";
            log += lastTurnStats;
        }


        void Game::playAll() {
            while (p1.isInTheGame() && p2.isInTheGame() && this->turn < 26)
                playTurn();
        }

        void Game::printWinner() const {
            if (p1.isInGame() || p2.isInGame())
                return;
            int p1Score = p1.cardesTaken();
            int p2Score = p2.cardesTaken();
            cout << ((p1Score > p2Score) ? "The winner is " + p1.getName() + :
                     (p1Score < p2Score) ? "The winner is " + p2.getName() + :
                     "draw!") << endl;
        }


        void Game::printStats() {
            // Display player 1's stats
            cout << "Player " << p1.getName() << ":\n";
            cout << "Cards won: " << p1.cardesTaken() << endl;
            cout << "Cards left: " << p1.stacksize() << endl;
            cout << "Win rate: " << fixed << setprecision(2) << (p1Wins / (float) turn) * 100 << "%" << endl;

            // Display player 2's stats
            cout << "Player " << p2.getName() << ":\n";
            cout << "Cards won: " << p2.cardesTaken() << endl;
            cout << "Cards left: " << p2.stacksize() << endl;
            cout << "Win rate: " << fixed << setprecision(2) << (p2Wins / (float) turn) * 100 << "%" << endl;

            // Display game statistics
            cout << "Total turns: " << turn << endl;
            cout << "Total draws: " << draws << endl;
            cout << "Draw rate: " << fixed << setprecision(2) << (draws / (float) turn) * 100 << "%" << endl;

            // Display winning player (if applicable)
            if (winner != nullptr) {
                cout << "Winning player: " << winner->getName() << endl;
            } else {
                cout << "Winning player: Game is not finished!" << endl;
            }
        }




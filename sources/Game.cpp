#include <iostream>
#include "game.hpp"
#include <stdexcept>
#include <string>
#include <vector>
#include <random>
#include <algorithm // for the random_shuffle
#include <cstdlib> // for the srand


namespace ariel{
    Game::Game(Player& player1, Player& player2) : p1(player1), p2(player2) , winner(nullptr) , lastTurnStats(""), turn(0), draws(0), player1Wins(0), player2Wins(0){

        if(player1.isInTheGame()){
            throw "player 1 is in the game";
        }
        if(player2.isInTheGame()){
            throw "player 2 is in the game";
        }

        Vector <Card> deck_of_cards;
        for(int i = 1; i < 14; i++){
            deck_of_cards.push_back(Card(cardValue)i, Leafs);
        }

        for(int i = 1; i < 14; i++){
            deck_of_cards.push_back(Card(cardValue)i, Diamonds);
        }

        for(int i = 1; i < 14; i++){
            deck_of_cards.push_back(Card(cardValue)i, Hearts);
        }

        for(int i = 1; i < 14; i++){
            deck_of_cards.push_back(Card(cardValue)i, Clovers);
        }


        /* now we need to shuffle the cards */
        // Shuffle the cards
        srand((unsigned int) time(NULL));
        random_shuffle(cards.begin(), cards.end());


        int player = 1;
        while(!cards.empty()){
            if (player == 1){
                p1.addCard(cards.back());
                player = 2;
            }
            else{
                p2.addCard(cards.back());
                player = 1;
            }
            cards.pop_back();
        }
        this->p1.setInGame(true);
        this->p2.setInGame(true);

        void Game::playTurn() {
            if (!p1.isInGame() || !p2.isInGame()) { //// Throw an exception if the game is over
                throw error("Game is over!");
            }

            turn++; // Increment turn counter

            if (turn > 26) { // Throw an exception if the game has gone on for too many turns
                throw error("Game cannot continue with more than 26 turns!");
            }

            /* Get cards from each player */
            Card p1Card = p1.getCard();
            Card p2Card = p2.getCard();

            /* Remove cards from each player's hand */
            p1.removeCard();
            p2.removeCard();

            // Add cards to the table
            vector<Card> tableCards = {p1Card, p2Card};

            // Handle a tie
            while (p1Card == p2Card) {
                // check if one of the players has no cards left in their stack or not enough cards to play
                if (p1.stacksize() <= 1 || p2.stacksize() <= 1) {
                    // divide the cards on the table evenly between the players
                    int cardsOnTable = tableCards.size();
                    int cardsPerPlayer = cardsOnTable / 2;
                    for (int i = 0; i < cardsPerPlayer; i++) {
                        p1.addCardTaken(tableCards[i]);
                        p2.addCardTaken(tableCards[i + cardsPerPlayer]);
                    }
                    break;
                }

                // Add cards to the table
                tableCards.push_back(p1.getCard());
                tableCards.push_back(p2.getCard());

                // Remove cards from each player's hand
                p1.removeCard();
                p2.removeCard();

                // Update the current cards being played
                p1Card = tableCards.back();
                p2Card = tableCards[tableCards.size() - 2];
            }

            // Determine the winner of the turn
            if (p1Card > p2Card) {
                // Player 1 wins the turn
                p1Wins++;
                for (Card c : tableCards) {
                    p1.addCardTaken(c);
                }
                log += "Turn " + to_string(turn) + ":\n" + p1.getName() + " played " + p1Card.toString() + " " + p2.getName() + " played " + p2Card.toString() + ". " + p1.getName() + " won the round!\n";
            }
            else if (p2Card > p1Card) {
                // Player 2 wins the turn
                p2Wins++;
                for (Card c : tableCards) {
                    p2.addCardTaken(c);
                }
                log += "Turn " + to_string(turn) + ":\n" + p1.getName() + " played " + p1Card.toString() + " " + p2.getName() + " played " + p2Card.toString() + ". " + p2.getName() + " won the round!\n";
            }
            else {
                // Tie
                for (Card c : tableCards) {
                    p1.addCardTaken(c);
                }
                log += "Turn " + to_string(turn) + ":\n" + p1.getName() + " played " + p1Card.toString() + " " + p2.getName() + " played " + p2Card.toString() + ". Draw!\n";
            }

            // Determine if the game





            this->player1 = player1;
        this->player2 = player2;
        player1.setIsPlaying(true);
        player2.setIsPlaying(true);
    }


    Game::Game(){ //another construnctor we gonna use
    }


    void Game::playTurn(){


    }


    void Game::printLastTurn(){


    }



    void Game::printWiner(){


    }


    void Game::printLog(){


    }


    void Game::printStats(){

    }
}



#pragma once
#include "Card.hpp"
#include "Player.hpp"
#include <vector>

namespace ariel{
    class Game{
        private:
            Player& p1;
            Player& p2;
            Player *winner;    //reference to the winner
            string lastTurnStats;
            string log;   //log of all turns
            unsigned int turn;
            unsigned int draws; //number of draws in the game
            unsigned int p1Wins; // number of times player 1 wins
            unsigned int p2Wins; // number of times player 2 wins

        public:
            Game(Player& plr1, Player& plr2); //constructor for thee game, getting two players

            void playTurn();

            void printLastTurn() const {cout << lastTurnStats << endl; } //note The function is const and can be called on a const object.

            void playAll();

            void printWiner() const; //note The function is const and can be called on a const object.

            void printLog() const {cout << log << endl;} //inline method

            void printStats();
    };
}
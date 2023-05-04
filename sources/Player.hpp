
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Card.hpp"

using namespace std;

namespace ariel{
    class Player{
        private: //does not need to write private, but for being clear
            string name;
            vector<Card> hand;
            bool inGame;
            int takenCards;
            
        public:
            Player(string name = "Default Player"); //constructor

            /*getters and setters*/
  
            int stacksize() const { //note The function is const and can be called on a const object.
                return (int)this->hand.size(); 
            }

            int cardesTaken() const { //note The function is const and can be called on a const object.
                return this->takenCards; 
            }

            void addCardTaken() { this->takenCards++; } //inline function

            const Card& getCard() const {  //note The function is const and can be called on a const object.
                return this->hand.back();
            }

            string getName() const { //note The function is const and can be called on a const object.
                return this->name; 
            }

            bool isInGame() const { //note The function is const and can be called on a const object.
                return this->inGame; 
            }


            void setInGame(bool inOrOut) { this->inGame = inOrOut; } //inline function


            void addCard(Card& card);

            void removeCard() { this->hand.pop_back();} //inline function
            
            bool hasCard(Card card) const; //note The function is const and can be called on a const object.


            /*return the string represntation of the object
              note The function is const and can be called on a const object.
            */
            string toString() const { 
                return "Player " + this->name + " has " + to_string(this->stacksize()) + " cards in hand and " + to_string(this->cardesTaken()) + " cards taken.";
            }
    };
}

#pragma once

#include <iostream>
#include <string>

/* Enumerations */

//enum for value
enum Value{Ace = 1, Two,Three ,Four ,Five ,Six ,Seven ,Eight ,Nine ,Ten ,Jack ,Queen ,King };

//enum for suit
enum Suit{Clubs = 1 ,Diamonds ,Hearts ,Spades};

using namespace std;

namespace ariel{
    class Card{
        private:
            Value value;
            Suit suit;

        public:
  
            Card(Value value = Ace, Suit suit = Clubs); //constructor with default values

            Value getValue() const { return value;} //note The function is const and can be called on a const object.

      
            Suit getSuit() const {return suit;} //note The function is const and can be called on a const object.

            bool operator==(const Card &rhs) const {return value == rhs.value;} //note The function is const and can be called on a const object.

            bool operator<(const Card &rhs) const; //compare two cards

            
            string toString() const; //should represent card with value & suit
    };
}
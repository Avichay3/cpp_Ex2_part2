#include <iostream>
#include <string>
using namespace std;

#include "Card.hpp"

namespace ariel {
    Card::Card(Value value, Suit suit): value(value), suit(suit) {};

    string Card::toString() const {
        string svalue, ssuit;
        Suit suit = this->getSuit();
        Value value = this->getValue();

        switch (value)
        {
            case Ace:
                svalue = "Ace";
                break;
            case Jack:
                svalue = "Jack";
                break;
            case Queen:
                svalue = "Queen";
                break;
            case King:
                svalue = "King";
                break;
            default:
                svalue = to_string((int)value);
                break;
        }

        switch (suit)
        {
            case Clubs:
                ssuit = "Clubs";
                break;
            case Diamonds:
                ssuit = "Diamonds";
                break;
            case Hearts:
                ssuit = "Hearts";
                break;
            case Spades:
                ssuit = "Spades";
                break;
        }

        return (svalue + " of " + ssuit);
    }

    bool Card::operator<(const Card &rhs) const {
        if (this->value == Ace and rhs.value == Two)
            return true;

        else if (this->value > Two and rhs.value == Ace)
            return true;

        return (this->value < rhs.value);
    }
}
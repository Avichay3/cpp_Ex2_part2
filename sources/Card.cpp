#include <iostream>
#include <string>
using namespace std;

#include "Card.hpp"

namespace ariel {
    Card::Card(Value value, Suit suit) : value(value), suit(suit) {}

    string Card::toString() const {
        string s_value, s_suit;

        if (value == Ace) {
            s_value = "Ace";
        } else if (value == Jack) {
            s_value = "Jack";
        } else if (value == Queen) {
            s_value = "Queen";
        } else if (value == King) {
            s_value = "King";
        } else {
            s_value = to_string(static_cast<int>(value));
        }

        switch (suit) {
            case Clubs:
                s_suit = "Clubs";
                break;
            case Diamonds:
                s_suit = "Diamonds";
                break;
            case Hearts:
                s_suit = "Hearts";
                break;
            case Spades:
                s_suit = "Spades";
                break;
        }

        return s_value + " of " + s_suit;
    }

    bool Card::operator<(const Card &r) const {
        if ((value == Ace && r.value == Two) || (value > Two && r.value == Ace)) {
            return true;
        }
        return value < r.value;
    }
}

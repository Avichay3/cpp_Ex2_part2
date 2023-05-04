/*The next code defines a class named Card with a private data members val of type cardValue and shape of type Shape.
 * cardValue and Shape are both a two separate enums that define the possible values for a card (Ace, Two, Three, Four..) and the shape of the card (Leafs, Diamonds, Hearts, Clovers), respectively.

The class has a default constructor that takes no arguments and sets the default value to Ace and Leafs.
The class also has two public member functions, getCardValue() and getShape(), that return the value of the card and its shape, respectively.
these functions are marked as const because they do not modify the state of the object.
*/


#include "Card.hpp"

#include <iostream>
#include <string>

using namespace std;

namespace ariel {
    Card::Card(cardValue val1, Shape shape1) : val(val1), shape(shape1) {}

    cardValue Card::getCardValue() const {
        return val;
    }

    Shape Card::getShape() const {
        return shape;
    }

    string Card::cardValueToString(cardValue val) const {
        string str_val;
        switch (val) {
            case Ace:
                str_val = "Ace";
                break;
            case Two:
                str_val = "Two";
                break;
            case Three:
                str_val = "Three";
                break;
            case Four:
                str_val = "Four";
                break;
            case Five:
                str_val = "Five";
                break;
            case Six:
                str_val = "Six";
                break;
            case Seven:
                str_val = "Seven";
                break;
            case Eight:
                str_val = "Eight";
                break;
            case Nine:
                str_val = "Nine";
                break;
            case Ten:
                str_val = "Ten";
                break;
            case Jack:
                str_val = "Jack";
                break;
            case Queen:
                str_val = "Queen";
                break;
            case King:
                str_val = "King";
                break;
        }
        return str_val;
    }



    /* the next function takes Shape value and convert it to string */
    string Card::shapeToString(Shape shape) const {
        string str_shape;
        switch (shape) {
            case Leafs:
                str_shape = "Leafs";
                break;
            case Diamonds:
                str_shape = "Diamonds";
                break;
            case Hearts:
                str_shape = "Hearts";
                break;
            case Clovers:
                str_shape = "Clovers";
                break;
        }
        return str_shape;
    }

    /* A string representation for the card */
    string Card::toString() const {
        return cardValueToString(val) + " of " + shapeToString(shape);
    }


    /* the next six functions are gonna compare two cards objects based on their values */


    bool Card::operator<(const Card &other) const {
        return (this->val < other.val);
    }

    bool Card::operator>(const Card &other) const {
        return (this->val > other.val);
    }

    bool Card::operator==(const Card &other) const {
        return (this->val == other.val);
    }

    bool Card::operator!=(const Card &other) const {
        return (this->val != other.val);
    }

    bool Card::operator<=(const Card &other) const {
        return (this->val <= other.val);
    }

    bool Card::operator>=(const Card &other) const {
        return (this->val >= other.val);
    }

}

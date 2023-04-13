#pragma once
#include <iostream>
#include <string>

enum cardValue{ Ace = 1, Two , Three , Four , Five , Six , Seven , Eight , Nine , Ten , Jack , Queen , King };
enum Shape{ Leafs = 1, Diamonds , Hearts , Clovers};

namespace ariel{
    class Card{
    private:
        cardValue val;
        Shape shape;

    public:     
        Card(cardValue val1 = Ace, Shape shape1 = Leafs); //if no arguments, deafault is Ace and Leaf

        cardValue getCardValue() const{ //the const is on *this*
            return val;
        }

        Shape getShape() const{ //same as before, the const is on *this* and that's why the const in this location
            return shape;
        }





    };
}
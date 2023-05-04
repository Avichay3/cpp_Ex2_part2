#include "Player.hpp"
#include <stdexcept>

namespace ariel {

    Player::Player(string name): name(name), takenCards(0), inGame(false) {};

    void Player::addCard(Card& card) { 
        if (this->hasCard(card))
            throw invalid_argument("Player have been already this card!");

        this->hand.push_back(card); 
    }

    bool Player::hasCard(Card card) const {
        for (size_t i = 0; i < this->stacksize(); ++i){
            Card t = this->hand.at(i);
            if ((t.getSuit() == card.getSuit()) && (t.getValue() == card.getValue()))
                return true;
        }
        return false;
    }
} 

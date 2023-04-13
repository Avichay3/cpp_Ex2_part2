#include "Player.hpp"
#include <stdexcept>

namespace ariel
{
    /* Constructor implementation */
    Player::Player(string name)
    {
        this->name = name;
        this->hand = vector<Card>();
        this->takenCards = 0;
        this->inGame = false;
    }

    /* AddCard implementation */
    void Player::addCard(Card& card)
    {
        if (this->stacksize() >= 26)
        {
            throw logic_error("Player already has the maximum number of cards.");
        }

        if (hasCard(card))
        {
            throw invalid_argument("Player already has the given card.");
        }

        this->hand.push_back(card);
    }

    /* HasCard implementation */
    bool Player::hasCard(Card card) const
    {
        for (const Card& c : this->hand)
        {
            if (c == card)
            {
                return true;
            }
        }
        return false;
    }
}

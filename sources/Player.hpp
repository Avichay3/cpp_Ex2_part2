#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "card.hpp"

namespace ariel
{
    class Player
    {
    private:
        std::string name;
        std::vector<Card> hand;
        int takenCards;
        bool inGame;

    public:
        Player(std::string name = "Default Player") : name(name), takenCards(0), inGame(false) {} //constructor

        std::string getName() const { return name; } //returns the name of the player without modify the object state

        bool isInGame() const { return inGame; }

        void setInGame(bool status) { inGame = status; }

        int stacksize() const { return hand.size(); }

        int cardsTaken() const { return takenCards; } //returns the number of cards taken by the player

        const Card& getCard() const { return hand.back(); }

        void addCard(Card& card);

        void removeCard() { hand.pop_back(); }

        bool hasCard(Card card) const;

        std::string toString() const {
            return "Player " + name + " has " + std::to_string(stacksize()) + " cards in hand and " + std::to_string(cardsTaken()) + " cards taken.";
        }
    };

    void Player::addCard(Card& card)
    {
        if (hand.size() == 26) {
            throw std::logic_error("Player has maximum number of cards (26)");
        }
        if (hasCard(card)) {
            throw std::invalid_argument("Player already has the given card");
        }
        hand.push_back(card);
    }

    bool Player::hasCard(Card card) const
    {
        for (const auto& c : hand) {
            if (c == card) {
                return true;
            }
        }
        return false;
    }
}

#include "Player.hpp"
#include <stdexcept>

namespace ariel {

    Player::Player(string name): name(name), takenCards(0), inGame(false) {};

    void Player::addCard(Card& card) {
        if (stacksize() >= 26) {
            throw std::runtime_error{"Player already has the maximum number of cards."};
        }
        if (hasCard(card)) {
            throw std::runtime_error{"Player already has the given card."};
        }
        hand.push_back(card);
    }

    bool Player::hasCard(Card card) const {
        for (const auto& c : hand) {
            if (c == card) {
                return true;
            }
        }
        return false;
    }

} // namespace ariel

#pragma once

#include <vector>
#include "card.hpp"
#include "player.hpp"

namespace ariel
{
    class Game
    {
    private:
        Player& p1; // reference to the first player
        Player& p2; //reference to the second player
        Player *winner; // reference to the winner of the game
        string lastTurnStats; // the last turn stats, we gonna use it in printLastTurn function

        unsigned int turn; // current turn for player, it is unsigned beacause a turn can be between 0-26
        unsigned int draws; // when both players play a card with the same value there is a draw.
        // this private member will keep truck of the number of draws in the game
        unsigned int p1Wins; // keep truck for the number of wins for player 1
        unsigned int p2Wins; // keep truck for the number of wins for player 2

    }
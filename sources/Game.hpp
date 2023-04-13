#include "player.hpp"

namespace ariel{
    class Game{
    public:
        Player player1, player2;
        Game(Player& player1, Player& player2);
        Game();
        void playTurn();
        void printLastTurn();

  
        void playAll ();
        void printWiner();
        void printLog();
        void printStats();
    };
}
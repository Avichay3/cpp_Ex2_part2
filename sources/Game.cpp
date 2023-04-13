#include "game.hpp"
#include <stdexcept>
#include <string>
using namespace std;
using namespace ariel;

Game::Game(Player& player1, Player& player2){
    if(player1.stacksize()>0 || player2.stacksize()>0){
        throw invalid_argument("both players are playing right now");
    }
    this->player1 = player1;
    this->player2 = player2;
    player1.setIsPlaying(true);
    player2.setIsPlaying(true);
}


Game::Game(){ //another construnctor we gonna use
}


void Game::playTurn(){


}


void Game::printLastTurn(){


}



void Game::printWiner(){


}


void Game::printLog(){


}


void Game::printStats(){

}
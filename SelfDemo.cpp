#include "sources/Player.hpp"
#include "sources/Card.hpp"
#include "sources/Game.hpp"
#include <iostream>
using namespace std;
using namespace ariel;

int main(){
    // Create two players with special names
    Player p1("Avichay");
    Player p2("Orel");
    cout << boolalpha << endl;
    
    // printing the status of the players before playing
    cout << "playing status for " << p1.getName() << " before starting the game is: " << p1.isInTheGame() << endl;
    cout << "playing status for " << p2.getName() << " before starting the game is: " << p2.isInTheGame() << endl;

    // create game with 2 players created
    Game game(p1, p2);
    // printing the status of the players when the game start
    cout << "playing status for " << p1.getName() << " after starting the game is: " << p1.isInTheGame() << endl;
    cout << "playing status for " << p2.getName() << " after starting the game is: " << p2.isInTheGame() << endl;
    // prints the amount of cards for "Avichay" and "Orel" before playing
    cout << "number of cards left before starting the game for " << p1.getName() << " is " << p1.stacksize()  << " cards" << endl;
    cout << "number of cards left before starting the game for " << p2.getName() << " is " << p2.stacksize()  << " cards" << endl;

    // start playing
    cout << "The game started" << endl;
    game.playAll();
    cout << "The game ended" << endl;
    // printing the last turn of the game
    cout << "printing the last turn of the game: " << endl;
    game.printLastTurn();
    // prints the amount of cards for "Avichay" and "Orel" after the game end
    cout << "number of cards left after the game end for " << p1.getName() << " is " << p1.stacksize()  << " cards" << endl;
    cout << "number of cards left after the game end for " << p2.getName() << " is " << p2.stacksize()  << " cards" << endl;
    // printing the status of the players after the game end
    cout << "playing status for " << p1.getName() << " after the game end is: " << p1.isInTheGame() << endl;
    cout << "playing status for " << p2.getName() << " after the game end is: " << p2.isInTheGame() << endl;
    // printing the winner of the game
    game.printWiner();
    // prints all the turns played one line per turn
    game.printLog();
    // for each player prints basic statistics: win rate, cards won, num of draws
    game.printStats();
    return 0;
}
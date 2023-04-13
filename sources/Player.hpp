#include <string>
using namespace std;

namespace ariel{
    class Player{
    private:
        string name;


  
        int cards_left, won_cards;
        bool is_playing;
    public:
        Player();
        Player(string name);
        int stacksize();
        int cardesTaken();
        string getName();
        void setName(string new_str);
        int getCardsLeft();
        void setCardsLeft(int new_cards_left);
        int getWonCards();
        void setWonCards( int new_won_cards);
        bool IsPlaying();
        void setIsPlaying(bool new_playing_status);
    };
}
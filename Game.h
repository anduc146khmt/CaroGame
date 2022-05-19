#include "Board.cpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Game {
private:
    Board caroBoard;
public:
    Game();
    void loadGame();
    void startGame();
    void PlayWithComputer();
    void PlayWithPlayer();
    void getStudentInfo();
    void getRule();
    ~Game();
};
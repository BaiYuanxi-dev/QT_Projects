#ifndef GAME_H
#define GAME_H
#define NUMOFGAME 8


#include <cstdlib>
#include <ctime>
#include <iostream>
using std::cout;
using std::endl;
class Game
{
public:
    Game(int level);
private:
    int level;
    int a[NUMOFGAME][NUMOFGAME];
    void initial();//初始化游戏
    bool judge(int a[NUMOFGAME][NUMOFGAME], int i, int j);
};

#endif // GAME_H

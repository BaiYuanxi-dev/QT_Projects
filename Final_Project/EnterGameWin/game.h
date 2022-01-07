#ifndef GAME_H
#define GAME_H
#define NUMOFGAME 8


#include <cstdlib>
#include <ctime>
#include <iostream>
using std::cout;
using std::endl;

//游戏类
class Game
{
public:
    /*
     * 构造函数
     * param: level 关卡
     * */
    Game(int level);

    /*
     * 访问数组元素
     * param: i j 要访问的数组下标
     * */
    int getIndex(int i, int j){ return a[i][j]; };

    /*
     * 修改数组元素为e的值
     * param: i j 要修改的数组下标  e 修改的值
     * */
    void setIndex(int i, int j, int e){ this->a[i][j] = e; };

private:
    int level;//关卡
    int a[NUMOFGAME][NUMOFGAME];//游戏数组
    void initial();//初始化游戏
    bool initJudge(int a[NUMOFGAME][NUMOFGAME], int i, int j);//判断是否有三个项链
};

#endif // GAME_H

#include "game.h"

Game::Game(int level)
{
    this->level = level;
    //初始化游戏数组，全部赋值为-1
    for(int i = 0; i < 8; i ++){
        for(int j = 0; j < 8; j ++){
            a[i][j] = -1;
        }
    }
    initial();
    for(int i = 0; i < 8; i ++){
        for(int j = 0; j < 8; j ++){
            cout << a[i][j] <<" ";
        }
        cout <<endl;
    };
}

void Game::initial(){
    bool isOk = false;
    //给数组赋值
    for(int i = 0; i < 8; i ++){
        for(int j = 0; j < 8; j ++){
            while(!isOk){
                a[i][j] = rand() % 4 + 1;
                isOk = initJudge(a, i, j);
            }
            isOk = false;
        }
    }
}

bool Game::initJudge(int a[NUMOFGAME][NUMOFGAME], int i, int j){
    if(i <= 1 && j <= 1){
        return true;
    }

    bool res = true;
    int index;

    if(i > 1){
        index = i;
        if(a[index][j] == a[index - 1][j] && a[index - 1][j] == a[index - 2][j]){
            res = false;
        }
    }

    if( j > 1 ){
        index = j;
        if(a[i][index] == a[i][index -1] && a[i][index - 1] == a[i][index - 2]){
            res = false;
        }
    }

    return res;
}

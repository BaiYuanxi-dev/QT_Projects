#include "mainwindow.h"

#include <QApplication>
#include <cstdlib>
#include <ctime>

#include "game.h"

//1.初始化的时候，不可以有元素被消除
//2.当元素被消除以后，总是会出现可被消除的组合，不能出现死局

//如果颜色个数是四 那么1 2 3 4 四个数字
//rand4()生成1-4的随机数
//填入一个二维的矩阵 （矩阵初始值可以设置为-1）
//然后写个方法验证下 填写这个元素在矩阵这个位置可不可以
//如果不可以就从新生成随机数 填入矩阵
//至于判断矩阵某个位置可以填入元素么 因为下 右都是-1 所以不用判断
//只要判断下左边和上面
//如果左边是相同数字 那么 再看左边的左边 是不是也是相同颜色
//如果是的话 就可以说明这个颜色不能填入 然后回去重新生成随机数字 当然
//可以直接排出那个上次失败的随机数字
//然后直到充满二维数组就可以了


//印象中好像很难保证第二个条件。大多数游戏选择在程序判断死局的时候自动
//重新洗牌。
//至于第一个，每次随机生成之后用程序判断有没有能消的，如果有就重新生成
//或者做细微的调整，虽然效率低点，对游戏来说还是可以接受的，毕竟问题规
//模不大。
//如果的确希望问题一定有解，可以考虑逆向生成：从全部消除掉的情况开始，
//每次添加进若干个连续的元素到随机的位置，然后进行一次旋转破换连续关系
//（这样消除的时候只要反过来旋转就能消掉了），如果一次旋转没有符合条件
//的就重来这一步。重复这个过程直到格子被完全填满。

bool judge(int a[8][8], int i, int j){
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
    //for(int index = i; index >= i - 1; index --){

    //}
}
int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();
    //假设现在有六种图片，要保存到8*8的数组中去
//    int a[8][8];
//    srand(time(nullptr));//    //初始化数组值为-1
//    for(int i = 0; i < 8; i ++){
//        for(int j = 0; j < 8; j ++){
//            a[i][j] = -1;

//        }
//    }

//    bool isOk = false;
//    //给数组赋值
//    for(int i = 0; i < 8; i ++){
//        for(int j = 0; j < 8; j ++){
//            while(!isOk){
//                a[i][j] = rand() % 4 + 1;
//                isOk = judge(a, i, j);
//            }
//            isOk = false;
//        }
//    }
    srand(time(nullptr));//    //初始化数组值为-1
    Game *g = new Game(1);
    return 0;
}

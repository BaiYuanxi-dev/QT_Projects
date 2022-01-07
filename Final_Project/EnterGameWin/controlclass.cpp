#include "controlclass.h"

//控制类构造函数
ControlClass::ControlClass(QObject *parent) : QObject(parent)
{
        QString* str;//排名字符串数组，待输入
        str = new QString[8];
        for(int i = 0; i < 8; i ++){
            str[i] = " 玩家信息  123 ";
        }

        str[5] = " nimass l e    ";
        str[3] = "asdsad ascdxin";
    //    RankWidget* r = new RankWidget(str, 8);
    //    r->show();
        //EnterGameWindow* w;


        //应该是点击了关卡按钮，进入关卡中间界面
        //直接new entergame对象
        w = new EnterGameWindow(1, str, 8);
        w->show();


        //中间窗口信号：返回关卡选择窗口
        //直接close然后delete
        connect(w, &EnterGameWindow::backToMain, this, [=](){
            cout << "back to mainWindow(in entergame widget)"<< endl;
        });


        //中间窗口信号：进入游戏
        connect(w, &EnterGameWindow::gameIn, this, [=](){
            cout << "in game" << endl;
            gameWidget = new GameWidget;
            gameWidget->show();

            //游戏窗口退出：返回关卡选择窗口
            //如果有继续游戏功能就不需要delete，否则需要delete
            connect(gameWidget, &GameWidget::backToMain, this, [=](){
                cout << "back to mainWindow(in game widget)"<< endl;
            });
        });



}

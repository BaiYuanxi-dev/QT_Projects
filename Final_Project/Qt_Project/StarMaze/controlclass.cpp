#include "controlclass.h"

//控制类构造函数
ControlClass::ControlClass(QObject *parent) : QObject(parent)
{
        QString* str;//排名字符串数组，待输入
        str = new QString[8];
        for(int i = 0; i < 8; i ++){
            str[i] = " ASDQW ASE ";
        }

        str[5] = " nimass l e    ";
        str[3] = "asdsad ascdxin";
    //    RankWidget* r = new RankWidget(str, 8);
    //    r->show();
        //EnterGameWindow* w;

        mainWin = new mianWindow;
        mainWin->show();

        connect(mainWin, &mianWindow::enterGameWid, this, [=](){
            w = new EnterGameWidget(1, str, 8);
            w->show();
            mainWin->setVisible(false);

            //应该是点击了关卡按钮，进入关卡中间界面
            //直接new entergame对象



            //中间窗口信号：返回关卡选择窗口
            //直接close然后delete
            connect(w, &EnterGameWidget::backToMain, this, [=](){
                mainWin->show();
                w->close();
                //cout << "back to mainWindow(in entergame widget)"<< endl;
            });


            //中间窗口信号：进入游戏
            connect(w, &EnterGameWidget::gameIn, this, [=](){
                game1 = new Widget;
                game1->show();
                w->setVisible(false);
                //cout << "in game" << endl;
    //            gamewidget = new GameWidget;
    //            gamewidget->show();
    //            //gameWidget = new GameWidget;
    //            //gameWidget->show();

                //游戏窗口退出：返回关卡选择窗口
                //如果有继续游戏功能就不需要delete，否则需要delete
                connect(game1, &Widget::backToMain, this, [=](){
                    //cout << "back to mainWindow(in game widget)"<< endl;
                    mainWin->setVisible(true);
                    game1->close();

                });
            });
        });




}

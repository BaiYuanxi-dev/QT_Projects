#ifndef ENTERGAMEWINDOW_H
#define ENTERGAMEWINDOW_H

#include <QMainWindow>
#include <QListWidget>
QT_BEGIN_NAMESPACE
namespace Ui { class EnterGameWindow; }
QT_END_NAMESPACE

class EnterGameWindow : public QMainWindow
{
    Q_OBJECT

public:
    EnterGameWindow(int level = 1, QString *rankStr = nullptr, QWidget *parent = nullptr);
    ~EnterGameWindow();
    void closeEvent(QCloseEvent *event);
signals:
    void backToMain();//点击退出，回到游戏关卡选择界面（MainWindow）
private:
    Ui::EnterGameWindow *ui;

    const int numOfRank = 8;//排名个数

    int level;//表示关卡数字

    QString *rankStr;//存储排名信息字符串 的 数组: 默认取前5？


    //QListWidget* rankWidget;

    void setRankWidget();


};
#endif // ENTERGAMEWINDOW_H

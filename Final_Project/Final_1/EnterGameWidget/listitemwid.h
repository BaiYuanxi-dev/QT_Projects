#ifndef LISTITEMWID_H
#define LISTITEMWID_H

#include <QWidget>

namespace Ui {
class ListItemWid;
}

//class ListItemWid : public QWidget
//{
//    Q_OBJECT

//public:
//    explicit ListItemWid(QWidget *parent = nullptr);
//    ~ListItemWid();

//private:
//    Ui::ListItemWid *ui;
//};

//#endif // LISTITEMWID_H


#include <QLabel>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QPainter>

/**
 * @brief The listItemWidget class
 * 排行榜每一条的窗口
 */
class ListItemWid : public QWidget
{
    Q_OBJECT
public:

    /*
     * 构造函数
     * param:
     *      rank 排名的名次
     *      rankStr 存储排名信息的字符串
     *      pathOfImg 头像路径的字符串
     *
     * */
    explicit ListItemWid(int rank = 1, QString rankStr = nullptr, QString pathOfImg = nullptr, QWidget *parent = nullptr);
    ~ListItemWid();


signals:


private:
    Ui::ListItemWid *ui;
    int rank; //名次
    QString rankStr;//存储排名信息字符串
    QString pathOfImg; //存储头像路径信息

    //QLabel* rankLabel;//存放排名数字的标签
    //QLabel* imgLabel;//存放排名照片的标签

    //QLineEdit* msgLine;


    //QHBoxLayout* hLayOut;//水平布局
    //QGridLayout * grid;

    void setItemWidget();//根据参数设置ItemWidget
};

#endif // LISTITEMWIDGET_H

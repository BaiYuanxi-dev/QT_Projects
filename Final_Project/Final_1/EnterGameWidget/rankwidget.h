#ifndef RANKWIDGET_H
#define RANKWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include "listitemwidget.h"
#include <QPainter>

/**
 * @brief The RankWidget class
 * 排名窗口
 */
class RankWidget : public QWidget
{
    Q_OBJECT
public:

    /*
     * 构造函数
     * param:
     *      rankStr 存储排名信息字符串
     *      numOfRank 字符串数组长度
     * */
    explicit RankWidget(QString *rankStr = nullptr, int numOfRank = 8, QWidget *parent = nullptr);
    ~RankWidget();
signals:

private:
    int numOfRank;//排行榜个数

    QString *rankStr;//存储排名信息字符串 的 数组: 默认取前5？

    listItemWidget** listItems;//排行榜每一条的窗口

    QVBoxLayout* vLayout;//垂直布局

    QLabel* titleLabel;

    /*
     * 设置窗口
     * */
    void setRankWidget();

    /*
     * 设置背景图片
     * */
    void setBk();

};

#endif // RANKWIDGET_H

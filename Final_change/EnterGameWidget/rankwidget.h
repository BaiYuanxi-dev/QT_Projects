#ifndef RANKWIDGET_H
#define RANKWIDGET_H

#include <QWidget>

namespace Ui {
class RankWidget;
}

class RankWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RankWidget(QString *rankStr, QWidget *parent = nullptr);
    ~RankWidget();

private:
    Ui::RankWidget *ui;
    QString *rankStr;
    void setBk();
    void setLabels();
};

#endif // RANKWIDGET_H

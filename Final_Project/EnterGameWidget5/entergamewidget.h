#ifndef ENTERGAMEWIDGET_H
#define ENTERGAMEWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class EnterGameWidget; }
QT_END_NAMESPACE

class EnterGameWidget : public QWidget
{
    Q_OBJECT

public:
    EnterGameWidget(QWidget *parent = nullptr);
    ~EnterGameWidget();

private:
    Ui::EnterGameWidget *ui;
};
#endif // ENTERGAMEWIDGET_H

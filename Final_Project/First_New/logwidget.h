#ifndef LOGWIDGET_H
#define LOGWIDGET_H

#include <QWidget>
#include <QPushButton>
class LogWidget : public QWidget
{
    Q_OBJECT
public:
    LogWidget(QWidget *parent = nullptr);
signals:
    void log();
private:
    QPushButton* logButton;
};

#endif // LOGWIDGET_H

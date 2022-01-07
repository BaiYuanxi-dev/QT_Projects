#ifndef MSGDIALOG_H
#define MSGDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include "position.h"
class MsgDialog : public QDialog
{
    Q_OBJECT
public:
    explicit MsgDialog(QDialog *parent = nullptr);
    void setTheDialog(Position* position, int no);
    string getSubsTime(int seconds1, int seconds2);
private:
    QLabel* titleLabel;

    QLabel* carIdLabel;
    QLabel* time1Label;
    QLabel* time2Label;
    QLabel* moneyLabel;
    QLineEdit* carIdLine;
    QLineEdit* time1Line;
    QLineEdit* time2Line;
    QLineEdit* moneyLine;


signals:

};

#endif // MSGDIALOG_H

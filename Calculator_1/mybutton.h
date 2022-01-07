#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QObject>
#include <QPushButton>
using namespace std;

//my own button class which extends QPushButton
class MyButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyButton(QPushButton *parent = nullptr);

    //set the position, size and text of button
    QPushButton& setThisButton(QWidget* parent, int x, int y, int width, int height, const char* text);

    //function to response "click button"
    void sendButtonText();

signals:
    //signal of clicked button
    void isClickedButton(const string &text);
};

#endif // MYBUTTON_H

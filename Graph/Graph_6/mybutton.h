#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include <string>
using namespace std;
class MyButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyButton(QPushButton *parent = nullptr);
    void setThisButton(int x, int y, string name);
    bool getIsEnter(){ return isEnter; };
    void setIsEnter(bool isEn){ isEnter = isEn; };
signals:
private:
    bool isEnter;

};

#endif // MYBUTTON_H

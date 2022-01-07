#ifndef CALCULATORWIN_H
#define CALCULATORWIN_H

#include <QWidget>
#include <QPushButton>
#include<QLineEdit>
#include "mybutton.h"

//gui of calculator
class CalculatorWin : public QWidget
{
    Q_OBJECT

public:
    CalculatorWin(QWidget *parent = nullptr);
    ~CalculatorWin();

    //write string to line edit
    void setLineText(string ch);

    //get result of expression
    void getResult(string& expression);

private:
    //backspack button "<-"
    MyButton *backspace;

    //"CE" button
    MyButton *ceButton;

    //number button
    MyButton *numButton0, *numButton1, *numButton2, *numButton3, *numButton4, *numButton5,
        *numButton6, *numButton7, *numButton8, *numButton9;

    //point button "."
    MyButton *pointButton;

    //addition("+"), subtraction("-"), multiplication("*"), division("/"), left parentheses ("("), right parentheses(")") button
    MyButton *addButton, *subsButton, *multiButton, *divButton, *leftParenthesesButton, *rightParenthesesButton;

    //equal sign("=")
    MyButton *equalButton;

    //line edit
    QLineEdit *line;


};
#endif // CALCULATORWIN_H

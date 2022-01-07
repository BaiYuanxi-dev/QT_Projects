#include "calculatorwin.h"
#include "Stack.hpp"
#include "tools.h"
#include <QDebug>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

//initial the calculator
CalculatorWin::CalculatorWin(QWidget *parent)
    : QWidget(parent)
{
    //set size and title of all window
    this->resize(542, 616);
    this->setWindowTitle("计算器");

    //set line edit
    line = new QLineEdit;
    line->setParent(this);
    line->setGeometry(35, 20, 475, 60);
    line->setText("");
    line->setAlignment(Qt:: AlignRight);
    line->setFont(QFont("Segoe Print", 18));

    //set backspack button "<-"
    backspace = new MyButton;
    backspace->setThisButton(this, 35, 105, 175, 75, "<-");
    connect(backspace, &MyButton:: isClickedButton, this, &CalculatorWin:: setLineText);

    //set "CE" button
    ceButton = new MyButton;
    ceButton->setThisButton(this, 235, 105, 275, 75, "CE");
    connect(ceButton, &MyButton:: isClickedButton, this, &CalculatorWin:: setLineText);

    //set number button
    numButton0 = new MyButton;
    numButton0->setThisButton(this, 35, 505, 175, 75, "0");
    connect(numButton0, &MyButton:: isClickedButton, this, &CalculatorWin:: setLineText);

    numButton1 = new MyButton;
    numButton1->setThisButton(this, 35, 405, 75, 75, "1");
    connect(numButton1, &MyButton:: isClickedButton, this, &CalculatorWin:: setLineText);


    numButton2 = new MyButton;
    numButton2->setThisButton(this, 135, 405, 75, 75, "2");
    connect(numButton2, &MyButton:: isClickedButton, this, &CalculatorWin:: setLineText);


    numButton3 = new MyButton;
    numButton3->setThisButton(this, 235, 405, 75, 75, "3");
    connect(numButton3, &MyButton:: isClickedButton, this, &CalculatorWin:: setLineText);


    numButton4 = new MyButton;
    numButton4->setThisButton(this, 35, 305, 75, 75, "4");
    connect(numButton4, &MyButton:: isClickedButton, this, &CalculatorWin:: setLineText);


    numButton5 = new MyButton;
    numButton5->setThisButton(this, 135, 305, 75, 75, "5");
    connect(numButton5, &MyButton:: isClickedButton, this, &CalculatorWin:: setLineText);


    numButton6 = new MyButton;
    numButton6->setThisButton(this, 235, 305, 75, 75, "6");
    connect(numButton6, &MyButton:: isClickedButton, this, &CalculatorWin:: setLineText);


    numButton7 = new MyButton;
    numButton7->setThisButton(this, 35, 205, 75, 75, "7");
    connect(numButton7, &MyButton:: isClickedButton, this, &CalculatorWin:: setLineText);


    numButton8 = new MyButton;
    numButton8->setThisButton(this, 135, 205, 75, 75, "8");
    connect(numButton8, &MyButton:: isClickedButton, this, &CalculatorWin:: setLineText);


    numButton9 = new MyButton;
    numButton9->setThisButton(this, 235, 205, 75, 75, "9");
    connect(numButton9, &MyButton:: isClickedButton, this, &CalculatorWin:: setLineText);



    //set signal button
    pointButton = new MyButton;
    pointButton->setThisButton(this, 235, 505, 75, 75, ".");
    connect(pointButton, &MyButton:: isClickedButton, this, &CalculatorWin:: setLineText);




    addButton = new MyButton;
    addButton->setThisButton(this, 335, 205, 75, 75, " + ");
    connect(addButton, &MyButton:: isClickedButton, this, &CalculatorWin:: setLineText);

    subsButton = new MyButton;
    subsButton->setThisButton(this, 335, 305, 75, 75, " - ");
    connect(subsButton, &MyButton:: isClickedButton, this, &CalculatorWin:: setLineText);

    multiButton = new MyButton;
    multiButton->setThisButton(this, 335, 405, 75, 75, " * ");
    connect(multiButton, &MyButton:: isClickedButton, this, &CalculatorWin:: setLineText);

    divButton = new MyButton;
    divButton->setThisButton(this, 335, 505, 75, 75, " / ");
    connect(divButton, &MyButton:: isClickedButton, this, &CalculatorWin:: setLineText);


    leftParenthesesButton = new MyButton;
    leftParenthesesButton->setThisButton(this, 435, 205, 75, 75, " ( ");
    connect(leftParenthesesButton, &MyButton:: isClickedButton, this, &CalculatorWin:: setLineText);

    rightParenthesesButton = new MyButton;
    rightParenthesesButton->setThisButton(this, 435, 305, 75, 75, " ) ");
    connect(rightParenthesesButton, &MyButton:: isClickedButton, this, &CalculatorWin:: setLineText);

    equalButton = new MyButton;
    equalButton->setThisButton(this, 435, 405, 75, 175, "=");
    connect(equalButton, &MyButton:: isClickedButton, this, &CalculatorWin:: setLineText);



}

CalculatorWin::~CalculatorWin()
{
    delete backspace;
    delete ceButton;
    delete numButton0;
    delete numButton1;
    delete numButton2;
    delete numButton3;
    delete numButton4;
    delete numButton5;
    delete numButton6;
    delete numButton7;
    delete numButton8;
    delete numButton9;

    delete pointButton;
    delete addButton;
    delete subsButton;
    delete multiButton;
    delete divButton;
    delete leftParenthesesButton;
    delete rightParenthesesButton;
    delete equalButton;
    delete line;
}


//get result of expression
void CalculatorWin::getResult(string& expression){
    expression = expression + " #";
    string s = "";
    double res;
    try {
        res = cal(expression);
    } catch (const char* error) {
        if( strcmp(error, "no means") == 0){
            line->setText("error");
            return;
        }
    }

    int num;
    if (res - (int)res == 0) {
        num = (int)res;
        s = to_string(num);
    } else {
        s = to_string(res);

        //减去字符中多余的0
        int i;
        for ( i = s.size() - 1; i > 0; i-- ) {
            if(s[i] != '0'){
                break;
            }
        }
        s.erase(i+1);
    }
    line->setText(s.c_str());
}

//write string to line edit
void CalculatorWin::setLineText(string ch){
    //读取文本框字符串
    string s = line->text().toStdString();


    //表达式检查


    //若上次计算结果为false
    if (s == "false") {
        if ( ch != "<-" && ch != "CE") {
            return;
        }
    }

    //最开始不能先输入符号（第一个应该是数字或者左括号）
    if (s == "") {
        if ( ch == " + " || ch == " - " || ch == " * " || ch == " / " || ch == "." || ch == " ) ") {
            return;
        }
    }


    //数字签名不能是右括号
    if (ch == "0" || ch == "1" || ch == "2" || ch == "3" || ch == "4" || ch == "5"
            || ch == "6" || ch == "7" || ch == "8" || ch == "9" ) {
        if (s[s.size() - 1] == ' ' && s[s.size() - 2] == ')') {
            return;
        }
    }

    //加乘除和右括号 前 不能直接是加减乘除，左括号和小数点
    if (ch == " + " || ch == " * " || ch == " / " || ch == " ) ") {
        if (s[s.size() - 1] == ' ') {
            if (s[s.size() - 2] == '+' || s[s.size() - 2] == '-' || s[s.size() - 2] == '*'
                    || s[s.size() - 2] == '/' || s[s.size() - 2] == '(' ){
                return;
            }
        } else if (s[s.size() - 1] == '.'){
            return;
        }
    }

    if (ch == " - ") {
        if (s[s.size() - 1] == ' ') {
            if (s[s.size() - 2] == '+' || s[s.size() - 2] == '-' || s[s.size() - 2] == '*'
                    || s[s.size() - 2] == '/' ){
                return;
            } else if (s[s.size() - 2] == '(') {
                ch = " -";
            }
        } else if (s[s.size() - 1] == '.'){
            return;
        }
    }

    //左括号前不能是数字或小数点
    if (ch == " ( ") {
        if(s[s.size() - 1] == '0' || s[s.size() - 1] == '1' || s[s.size() - 1] == '2'
                || s[s.size() - 1] == '3' || s[s.size() - 1] == '4' || s[s.size() - 1] == '5'
                || s[s.size() - 1] == '6' || s[s.size() - 1] == '7' || s[s.size() - 1] == '8'
                || s[s.size() - 1] == '9' || s[s.size() - 1] == '.') {
            return;
        }
    }

    //小数点前不能是运算符或者括号
    if (ch == ".") {
        if (s[s.size() - 1] == ' ') {
            if (s[s.size() - 2] == '+' || s[s.size() - 2] == '-' || s[s.size() - 2] == '*'
                    || s[s.size() - 2] == '/' || s[s.size() - 2] == '(' || s[s.size() - 2] == ')' ) {
                return;
            }
        } else if (s[s.size() - 1] == '.') {
            return;
        } else if (s[s.size() - 1] == '0' || s[s.size() - 1] == '1' || s[s.size() - 1] == '2'
                   || s[s.size() - 1] == '3' || s[s.size() - 1] == '4' || s[s.size() - 1] == '5'
                   || s[s.size() - 1] == '6' || s[s.size() - 1] == '7' || s[s.size() - 1] == '8'
                   || s[s.size() - 1] == '9'){
            for (int j = s.size() - 1; j > 0 && s[j] != ' '; j --) {
                if (s[j] == '.') {
                    return;
                }
            }
        }
    }

    //等于前面不能是运算符或者左括号
    if(ch == "="){
        if (s[s.size() - 1] == ' ') {
            if (s[s.size() - 2] == '+' || s[s.size() - 2] == '-' || s[s.size() - 2] == '*'
                    || s[s.size() - 2] == '/' || s[s.size() - 2] == '(' ){
                return;
            }
        }
    }

    if (ch != "<-" && ch != "CE" && ch != "=") {
        //读到的（点击的）是数字是
        s += ch;
        line->setText(s.c_str());
    } else if (ch == "<-") {

        //独到的是是退格符
        if (s[s.size() - 1] == ' ' && (s[s.size() - 2] == '+' || s[s.size() - 2] == '-' || s[s.size() - 2] == '*'
                                      || s[s.size() - 2] == '/' || s[s.size() - 2] == '('  || s[s.size() - 2] == ')') ){
            s.erase(s.size() - 3);
            line->setText(s.c_str());
        } else if (s != "") {
            s.erase(s.size() - 1);
            line->setText(s.c_str());
        }
    } else if (ch == "CE") {
        //读到清空符
        if (s != "") {
            line->setText("");
        }
    } else {
        //读到等号(实际上是"#"号)
        //括号匹配检查
        if (parenthesesMatch(s)) {
            //计算并得出结果
            getResult(s);
        } else {
            s = "false";
            line->setText(s.c_str());
        }
    }
}




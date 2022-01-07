#include"Stack.hpp"
#include<iostream>
#include<sstream>
#include <cstdlib>
#include<string>
using namespace std;

//signal string
const string ADD = "+";
const string SUBS = "-";
const string MUL = "*";
const string DIV = "/";
const string LEFT_BRACKETS = "(";
const string RIGHT_BRACKETS = ")";
const string POUND_SIGN = "#";
const string POINT = ".";

//get priority of operator
int getPriority(LinkedStack<string>& stack, const string op) {
    int res = 2;

    //string at the top of the stack
    string topString;

    try {
        topString = stack.getTop();
    }
    catch (const char* error) {
        cout << error << endl;
    }

    //compare priority of operators
    if (topString == ADD || topString == SUBS) {
        if (op == ADD || op == SUBS || op == RIGHT_BRACKETS || op == POUND_SIGN ) {
            res = 1;
        }
        else if (op == MUL || op == DIV || op == LEFT_BRACKETS) {
            res = -1;
        }
    }
    else if (topString == MUL || topString == DIV) {
        if (op == ADD || op == SUBS || op == MUL || op == DIV || op == RIGHT_BRACKETS || op == POUND_SIGN) {
            res = 1;
        }
        else if (op == LEFT_BRACKETS) {
            res = -1;
        }
    }
    else if (topString == LEFT_BRACKETS) {
        if (op == ADD || op == SUBS || op == MUL || op == DIV || op == LEFT_BRACKETS) {
            res = -1;
        }
        else if (op == RIGHT_BRACKETS) {
            res = 0;
        }
        else if (op == POUND_SIGN) {
            throw "Left brackets doesn't matching, wrong operator!";
        }
    }
    else if (topString == RIGHT_BRACKETS) {
        if (op == ADD || op == SUBS || op == MUL || op == DIV || op == RIGHT_BRACKETS || op == POUND_SIGN) {
            res = 1;
        }
        else if (op == LEFT_BRACKETS) {
            throw "Right brackets doesn't matching, wrong operator!";
        }
    }
    else if (topString == POUND_SIGN) {
        if (op == ADD || op == SUBS || op == MUL || op == DIV || op == LEFT_BRACKETS) {
            res = -1;
        }
        else if (op == POUND_SIGN) {
            res = 0;
        }
        else if (op == RIGHT_BRACKETS) {
            throw "Wrong operator,right brackets doesn't matching!";
        }
    }
    return res;
}

//calculate according to two operands and operator
double basicOperate(double operand1, double operand2, string oper) {
    double res = 0;
    if (oper == ADD) {
        res = operand1 + operand2;
    }
    else if (oper == SUBS) {
        res = operand1 - operand2;
    }
    else if (oper == MUL) {
        res = operand1 * operand2;
    }
    else if (oper == DIV) {
        res = operand1 / operand2;
    }
    return res;
}


//calculate result according to string of expression
double cal(string& op) {
    //store operands
    double operand1, operand2;

    //string stream to read operands and operators from string "op"
    istringstream is(op);
    string word = "";
    string tempString;

    //priority of operators
    int priority;

    //stack to store operands
    LinkedStack<double> opnd;
    //stack to store operators
    LinkedStack<string> optr;

    optr.push(POUND_SIGN);
    //read operands and operators from string "op"
    is >> word;


    while (word != POUND_SIGN || optr.getTop() != POUND_SIGN) {
        //read signals
        if (word == ADD || word == SUBS || word == MUL || word == DIV
            || word == LEFT_BRACKETS || word == RIGHT_BRACKETS || word == POUND_SIGN) {
            priority = getPriority(optr, word);

            //priority of operator read from word is bigger
            if (priority == -1) {
                optr.push(word);
                is >> word;
            }

            //equal
            else if (priority == 0) {
                optr.pop(tempString);
                is >> word;
            }

            //priority of operator read from word is smaller
            else if (priority == 1) {
                optr.pop(tempString);
                opnd.pop(operand2);
                opnd.pop(operand1);
                if(tempString == "/" && operand2 == 0){
                    throw "no means";
                }
                opnd.push(basicOperate(operand1, operand2, tempString));


            }
        }
        //read number
        else {
            opnd.push(atof(word.c_str()));
            is >> word;
        }

    }
    return opnd.getTop();
}

//check parentheses match
bool parenthesesMatch(string op) {
    LinkedStack<string> stack;
    string tempString;
    for (int i = 0; i < op.size(); i++) {
        if (op[i] == '(') {
            stack.push("(");
        }
        else if (op[i] == ')') {
            if (stack.IsEmpty()) {
                return false;
            }
            else {
                stack.pop(tempString);
            }
        }
    }
    return stack.IsEmpty();
}

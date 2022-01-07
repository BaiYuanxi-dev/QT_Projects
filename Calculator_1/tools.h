#ifndef TOOS_H
#define TOOS_H
#include"Stack.hpp"
#include<string>
using namespace std;

//int getPriority(LinkedStack<string>& stack, const string op);

//calculate according to two operands and operator
double basicOperate(double operand1, double operand2, string oper);

//check parentheses match
bool parenthesesMatch(string op);

//calculate result according to string of expression
double cal(string& op);
#endif // TOOS_H

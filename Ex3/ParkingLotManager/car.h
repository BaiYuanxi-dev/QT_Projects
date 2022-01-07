#ifndef CAR_H
#define CAR_H

#include <ctime>
#include <string>
#include <iostream>
using namespace std;

//car 类，存储汽车车牌，进入时间，应缴纳金额等数据
class Car
{
public:

    Car(string id = "", int timeIn = 0, double money = 0);
    ~Car();

    //get id of the car
    string getId() { return id; };

    //get parking time until now
    int getTime();

    //get money to pay
    double getMoney();

    //设置车牌
    void setId(string id) { this->id = id; };

    //设置进入时间
    void setTime(int time) { this->timeIn = time; };

    bool operator==(const Car& car);
private:
    string id;
    int timeIn;//时间？？
    double money;
};
#endif // CAR_H


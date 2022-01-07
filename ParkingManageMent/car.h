#ifndef CAR_H
#define CAR_H

#include <ctime>
#include <string>
#include <iostream>
using namespace std;

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

    void setId(string id) { this->id = id; };

    void setTime(int time) { this->timeIn = time; };

    bool operator==(const Car& car);
private:
    string id;
    int timeIn;//时间？？
    double money;
};
#endif // CAR_H


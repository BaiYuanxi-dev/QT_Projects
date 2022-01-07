#include "car.h"
#include <cstdlib>
#include <ctime>

Car::Car(string id, int time, double money)
{
    this->id = id;
    this->timeIn = time;
    this->money = money;
}

Car::~Car(){

}

//TODO
int Car::getTime(){
    return this->timeIn;
}


double Car::getMoney(){
    time_t nowTime;
    int subs;
    nowTime = time(NULL);
    subs = (int)nowTime - this->timeIn;
    //计费规则:前30s不收费，30-90s每秒1元，90+每秒1.5元
    double res = 0;

    if(subs <= 30){
        res = 0;
    } else if ( subs > 30 && subs <= 90 ) {
        res = ( subs - 30 );
    } else if ( subs > 90 ) {
        res = 60 + (subs - 90) * 1.5;
    }
    this->money = subs;
    return res;
}


bool Car::operator==(const Car& car){
    if (this->id == car.id) {
        return true;
    } else {
        return false;
    }
}

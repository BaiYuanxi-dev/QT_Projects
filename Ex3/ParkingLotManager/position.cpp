#include "position.h"

//initial the parking space
Position::Position(int no, bool isEmpty)
{
    this->no = no;
    //因为程序每次开始执行时就创建position对象
    //所以在创建position对象时首先初始化car对象
    this->car = new Car("#");
    this->isEmpty = isEmpty;
}

Position::~Position(){

}

void Position::setCar(string id, int time){
    this->car->setId(id);
    this->car->setTime(time);
}

void Position::setEmpty(bool f){
    this->isEmpty = f;
}

Car* Position::getCar(){
    return this->car;
}


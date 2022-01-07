#ifndef PARTINGLOT_H
#define PARTINGLOT_H

#include "linkedlist.hpp"
#include "Queue.hpp"
#include "position.h"
#include "car.h"

//this class is the abstract of parting lot
class PartingLot
{
public:
    //initial the parting lot
    PartingLot(int emptySize, int maxSize = 16);

    ~PartingLot();

    //register license plate number of car and enter the waiting queue
    PartingLot& regist(string id);

    //the front of the waiting queue enter the parking lot
    bool enter(int &noIn);

    //the car leave and return the money
    int out(int no);

    //query message of car at this parking space
    Position* query(int no);

    //print all message
    void showAll();

    //return empty car space
    int getEmptySize(){ return this->emptySize; };

    //return size of parking lot
    int getMaxSize() { return this->maxSize; };

    //return the positionList
    LinkedList<Position*>* getPositionList(){ return this->positionList; };

    int getQueueLength() { return this->queueLength; };

private:

    //capacity of parking lot
    int maxSize;

    //empty parking space of  parking lot
    int emptySize;

    int queueLength;

    //point to object which stores the state of waiting queue
    Queue<string> *waitingQueue;

    //point to object which stores the message of parking space
    LinkedList<Position*> *positionList;
};

#endif // PARTINGLOT_H

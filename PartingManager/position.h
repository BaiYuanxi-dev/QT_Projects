#ifndef POSITION_H
#define POSITION_H


#include <iostream>
class Position
{
public:
    //friend std::ostream& operator<<(std::ostream& out, const Position & position);
    Position(int no, bool isEmpty = true);

    ~Position();

    //get number of this parking space
    int getNo() { return no; };

    //return if the parking space is empty;
    bool ifEmpty() { return isEmpty; };

    void setCar(Car* car);

    void setEmpty(bool f);


private:
    //id of position
    int no;

    //if there is a car, let the pointer point to the car object,else it point to nullptr
    Car *car;

    //flag of empty
    bool isEmpty;


};

#endif // POSITION_H

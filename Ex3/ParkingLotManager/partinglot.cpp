#include "partinglot.h"
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>

//初始化停车场对象
PartingLot::PartingLot(int emptySize, int maxSize)
{
    this->emptySize = 16;
    this->queueLength = 0;
    //读文件
    fstream fin;
    fin.open("lot.txt", ios::in);

    //停车场车位编号
    int no;
    //汽车牌号
    string id;
    //车入车位时间
    int time;
    //剩余空位个数
    this->emptySize = emptySize;
    //最大空位个数
    this->maxSize = maxSize;
    positionList = new LinkedList<Position*>;
    Position* space;


    //initial each space of parking lot
    for (int i = 0; i < maxSize; i ++) {
        fin >> no >> id >> time;
        space = new Position(no);
        if ( id != "#" ) {
            space->getCar()->setId(id);
            space->getCar()->setTime(time);
            space->setEmpty(false);
            this->emptySize--;
        }
        positionList->insert(i+1, space);

    }
    waitingQueue = new Queue<string>;
    fin.close();
}

PartingLot::~PartingLot(){
    //delete positionList;
}

//车辆进入等待队列
PartingLot& PartingLot::regist(string id){
    waitingQueue->add(id);
    this->queueLength ++;
    return *this;
}

//随机进入空车位,从进入车位开始计时
bool PartingLot::enter(int &noIn){
    if (this->emptySize == 0) {
        //cout << "can't in" <<endl;
        return false;
    }

    if( this->waitingQueue->isEmpty() ){
        //队列空
        return false;
    }

    fstream fout;
    fout.open("lot.txt", ios::out);
    string carId;
    Position* position;
    time_t nowTime;

    //srand((unsigned)time(NULL));
    int randNum;
    if (positionList->length() <= maxSize) {
        //let the front of waiting queue out of the queue
        waitingQueue->del(carId);
        //随机选取空位置停放车
        while(this->emptySize != 0){
            //找到对应的车位
            randNum = rand() % 16 + 1;

            positionList->getElement(randNum, position);
            //设置当前位置
            if ( position->ifEmpty() ) {
                this->queueLength --;
                noIn = randNum;
                nowTime = time(NULL);
                position->setCar(carId, nowTime);
                position->setEmpty(false);
                emptySize--;
                //设置时间
                break;
            }

        }

        for (int i = 0; i < maxSize;i++ ) {
            this->positionList->getElement(i+1, position);
            if (position->ifEmpty()) {
                fout << i+1 << " # 0"<< endl;
            } else {
                fout << i+1 << " " << position->getCar()->getId()  << " " << position->getCar()->getTime() << endl;
            }
        }
        fout.close();

        return true;
    }
    return false;
}

//某位置的车离开停车场,应该返回费用
int PartingLot::out(int no){
    Position* position;
    Car* car;
    double money = 0;
    //处理
    positionList->getElement(no, position);
    car = position->getCar();
    if (position->ifEmpty()) {
        //这个位置本来就是空的
        return -1;
    } else {
        position->setEmpty(true);
        money = car->getMoney();
        position->setCar("#", 0);
        emptySize++;
    }

    fstream fout;
    fout.open("lot.txt", ios::out);
    for (int i = 0; i < maxSize;i++ ) {
        this->positionList->getElement(i+1, position);
        if (position->ifEmpty()) {
            fout << i+1 << " # 0"<< endl;
        } else {
            fout << i+1 << " " << position->getCar()->getId()  << " " << position->getCar()->getTime() << endl;
        }
    }
    fout.close();

    //计费
    return money;
}

//查询当前车位情况
Position* PartingLot::query(int no){
    Position* position;
    try {
        if ( !positionList->getElement(no, position) ) {
            throw "-1";
        }
    } catch (const char* error) {
        if (strcmp(error,"-1")) {
            //处理
            throw "not found";
        }
    }
    return position;
}

//打印所有车位的车辆信息
void PartingLot::showAll(){
    Position *temp;
    //每个position应该都可以输出吧
    for(int i = 0;i < this->maxSize;i ++){
        //处理
        positionList->getElement(i+1,temp);
        cout << temp->getNo() << ": ";
        //try {
        if(temp->getCar()->getId() != "#"){
            cout << temp->getCar()->getId() << " " << temp->getCar()->getTime() << temp->getCar()->getMoney() <<endl;
        } else {
            cout << "no car at this space"<<endl;
        }

    }
}

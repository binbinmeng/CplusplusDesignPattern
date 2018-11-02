//
// Created by lenovo on 2018/10/31.
//

#include "iostream"
using namespace std;

enum DOORTYPE{
    WOODEN =0,
    IRON=1
};

class IDoorBase{
public:
       virtual void makeDoor() =0;
};

class WoodenDoor: public IDoorBase{
public:
     WoodenDoor()
    {
       ;
    }

    void makeDoor()
    {
        std::cout<<"this is wooden door !"<<std::endl;
    }
};

class  IronDoor: public IDoorBase{
public:
    IronDoor()
    {

    }
    void makeDoor()
    {
        std::cout<<"this is iron door !"<<std::endl;
    }
};

class DoorFactory{
public:
    /*
     * 一个工厂对应多类产品
     */
    IDoorBase* makeDoor(enum DOORTYPE dtype)
    {
        if(dtype == WOODEN)
        {
            return   new WoodenDoor();
        }
        if(dtype == IRON)
        {
            return new IronDoor();
        }
        else
            return NULL;
    }
};

int main()
{
    DoorFactory * doorFactory = new DoorFactory();
    IDoorBase * door1 = doorFactory->makeDoor(DOORTYPE::WOODEN);
    door1->makeDoor();
    IDoorBase * door2 = doorFactory->makeDoor(DOORTYPE::IRON);
    door2->makeDoor();

    delete doorFactory;
    return  0;
}
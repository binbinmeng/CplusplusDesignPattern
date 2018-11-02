//
// Created by lenovo on 2018/10/31.
//

#include "iostream"
using namespace std;
class IDoorBase{
public:
    virtual void PrintDoor() =0;
};

class WoodenDoor: public IDoorBase{
public:
    WoodenDoor()
    {

    }
    void PrintDoor()
    {
        std::cout<<"this is wooden door !"<<std::endl;
    }
};

class  IronDoor: public IDoorBase{
public:
    IronDoor()
    {

    }
    void PrintDoor()
    {
        std::cout<<"this is iron door !"<<std::endl;
    }
};

class FactoryBase{
public:
    virtual IDoorBase* makeDoor() =0;
};

class WoodenFactory: public  FactoryBase{
public:
    /*
     * 一个工厂对应一类产品
     */
    IDoorBase * makeDoor(){
        return  new WoodenDoor();
    }
};

class IronFactory: public FactoryBase{
public:
    /*
   * 一个工厂对应一类产品
   */
    IDoorBase * makeDoor(){
        return new IronDoor();
    }
};

int main()
{
    FactoryBase * woodfactory = new WoodenFactory();
    IDoorBase* door1 = woodfactory->makeDoor();
    door1->PrintDoor();
    FactoryBase * ironfactory = new IronFactory();
    IDoorBase* door2 =ironfactory->makeDoor();
    door2->PrintDoor();

    delete woodfactory;
    delete ironfactory;

    return  0;
}
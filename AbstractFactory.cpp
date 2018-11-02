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
    void PrintDoor()
    {
        std::cout<<"this is wooden door !"<<std::endl;
    }
};

class  IronDoor: public IDoorBase{
public:
    void PrintDoor()
    {
        std::cout<<"this is iron door !"<<std::endl;
    }
};

class  IDesktopBase{
public:
    virtual void PrintDesktop() =0;
};

class WoodenDesktop: public IDesktopBase{
public:

    void PrintDesktop()
    {
        std::cout<<"this is wooden desktop !"<<std::endl;
    }
};

class IronDesktop: public IDesktopBase{
public:
    IronDesktop();
    void PrintDesktop(){
        std::cout<<"this is iron desktop !"<<std::endl;
    }
};

class FactoryBase{
public:
    virtual IDoorBase* makeDoor() =0;
    virtual IDesktopBase* makeDesktop() =0;
};

class WoodenFactory: public  FactoryBase{
public:
    /*
     * 多个工厂对应多类产品
     */
    IDoorBase * makeDoor(){
        return  new WoodenDoor();
    }
    IDesktopBase * makeDesktop(){
        return  new WoodenDesktop();
    }
};

class IronFactory: public FactoryBase{
public:
    /*
   * 多个工厂对应多类产品
   */
    IDoorBase * makeDoor(){
        return new IronDoor();
    }

    IDesktopBase * makeDesktop(){
        return new IronDesktop();
    }
};

int main()
{
    FactoryBase * wooden_factory = new WoodenFactory();
    IDoorBase* door1 = wooden_factory->makeDoor();
    door1->PrintDoor();
    IDesktopBase* desktop = wooden_factory->makeDesktop();
    desktop->PrintDesktop();

    delete wooden_factory;
    return 0;
}
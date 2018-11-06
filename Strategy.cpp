//
// Created by lenovo on 2018/11/6.
//
#include <iostream>
using namespace std;

class StrategyBase{
public:
    StrategyBase(){

    }

    ~StrategyBase(){

    }

    virtual void doInference() =0 ;
};

class StrategyA: public StrategyBase{
public:
    StrategyA(){

    }

    void doInference(){
        std::cout<<"this is strategy A !"<<std::endl;
    }
};

class StrategyB: public StrategyBase{
public:
    StrategyB(){

    }

    void doInference(){
        std::cout<<"this is strategy B !"<<std::endl;
    }
};

class Context{
public:
    Context(StrategyBase *strategy){
        this->strategy_m = strategy;
    }

    ~Context(){
        delete strategy_m;
    }

    void Inference(){
        strategy_m->doInference();
    }
private:
    StrategyBase *strategy_m;
};

int main(){

    Context * context = new Context(new StrategyA());

    context->Inference();

    delete context;

    return 0;
}


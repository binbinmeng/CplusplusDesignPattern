//
// Created by lenovo on 2018/10/31.
//
#include <iostream>
using namespace std;

template <class T>
class Compare{
public:
    Compare(const T& a,const T &b)
    {
        x = a;
        y = b;
    }

    T Max(){
        return x>=y?x:y;
    }

    T Min(){
        return x<=y?x:y;
    }

    T Sum();
private:
    T x;
    T y;
};

template <class T>
T Compare<T>::Sum() {
    return x + y;
}

int main(){
    Compare<float> compare(2,9);
    std::cout<<compare.Max()<<std::endl;
    std::cout<<compare.Sum()<<std::endl;
}

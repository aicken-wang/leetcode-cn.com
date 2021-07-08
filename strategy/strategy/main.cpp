//
//
//  strategy.cpp
//
//  Created by shunqing wang on 2021/6/11.
//

#include <iostream>
using namespace std;
enum class Play{
    A,
    B
};
class Strategy{
public:
    Strategy(){}
    virtual ~Strategy(){}
    virtual void doing() = 0; // 抽象方法
};
// 策略1
class PlayA:public Strategy
{
public:
    PlayA() {
        cout << "init play A" <<endl;
    }
    ~PlayA() {
        cout << "free play A" << endl;
    }
    virtual void doing() {
        cout << "PlayA doing()..." << endl;
    }
};

// 策略2
class PlayB:public Strategy
{
public:
    PlayB() {
        cout << "init play B" <<endl;
    }
    ~PlayB() {
        cout << "free play B" << endl;
    }
    virtual void doing() override {
        cout << "PlayB doing()..." << endl;
    }
};
class Context
{
private:
    Strategy* pStrategy = nullptr;
public:
    Context(Strategy* strategy):pStrategy(strategy) {
        cout << "init strategy" << endl;
    }
    void Do() {
        if(!pStrategy) {
            cout<< "not init" << endl;
        }
        pStrategy->doing();
    }
    void Destory() {
        if(!pStrategy) {
            cout << "double free" <<endl;
        }
        delete pStrategy;
        pStrategy = nullptr;
    }
    ~Context() {
        if(pStrategy)
            cout << "memory leak" << endl;
    }
};
void StrategyImpl(Play p){
    switch(p)
    {
        case Play::A:
        {
            Context* cxtA = new Context(new PlayA());
            cxtA->Do();
            cxtA->Destory();
            delete cxtA;
            break;
        }
        case Play::B:{
            Context* cxtB = new Context(new PlayB());
            cxtB->Do();
            cxtB->Destory();
            delete cxtB;
            break;
        }
        default:
            cout << "unknown..." << endl;
    }


}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    StrategyImpl(Play::A);
    StrategyImpl(Play::B);
    return 0;
}

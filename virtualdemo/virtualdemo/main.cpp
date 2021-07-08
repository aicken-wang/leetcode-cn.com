//
//  main.cpp
//  virtualdemo
//
//  Created by shunqing wang on 2021/6/12.
//

#include <iostream>
using namespace std;
class D
{
public:
    void printA()
    {
        cout<<"printA"<<endl;
    }
    virtual void printB()
    {
        cout<<"printB"<<endl;
    }
};
void main1()
{
    
    D *d = new D();
    d->printA();
    d->printB();
}
int main(int argc, const char * argv[]) {
    
    
    // insert code here...
    std::cout << "Hello, World!\n";
    main1();
    return 0;
}

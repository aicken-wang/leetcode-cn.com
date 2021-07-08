//
//  main.cpp
//  simpleFactory
//
//  Created by shunqing wang on 2021/6/11.
//

#include <iostream>
#include <string>
using namespace std;

enum class NetWork{
    HTTP = 0,
    HTTPS,
    TCP,
    QUIC,
    UDP,
    WS,
};

// 抽象基类
class Base{
    virtual void doing() = 0;
};
class Docker:public Base{
protected:
    string m_name;
public:
    explicit Docker():m_name("docker"){}
    explicit Docker(const string& name):m_name(name){}
    explicit Docker(const Docker& docker){
        this->m_name = docker.m_name;
    }
    Docker& operator=(const Docker& docker){
        if(this != &docker)
        {
            this->m_name = docker.m_name;
        }
        return *this;
    }
    
    virtual void doing() override{
        cout << "this server is name:"<< this->m_name<< endl;
    }
    void setName(const string& name){
        this->m_name = name;
    }
    string getName(){
        return m_name;
    }
};
// 策略实例2
class Server{
private:
    Docker m_docker;

public:
    explicit Server(){}
    explicit Server(const Docker& docker){
        m_docker = docker;
    }
    void getResult(){
        m_docker.doing();
    }
};

// 策略实例1
class Context{
private:
    Docker m_docker;
public:
    explicit Context(){};
    explicit Context(const Docker& docker){
        m_docker = docker;
    }
    void getResult() {
        m_docker.doing();
    };
    void  context_switch(const string& name){
        this->m_docker.setName(name);
    }
    void monitor(){
        cout << "context switch:"<< this->m_docker.getName()<< endl;
    }
    
};


void Strategy(NetWork net){
    Server s;
    Context c;
    switch (net) {
        case NetWork::HTTP:
            s = Server(Docker("http"));
            s.getResult();
            break;
        case NetWork::HTTPS:
            s = Server(Docker("https"));
            s.getResult();
            break;
        case NetWork::QUIC:
            s = Server(Docker("quic"));
            s.getResult();
            break;
        default:
            c = Context(Docker("idle"));
            c.context_switch("cpu runing");
            c.getResult();
            break;
    }
    
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    // 策略模式
    Strategy(NetWork::HTTP);
    Strategy(NetWork::QUIC);
    Strategy(NetWork::UDP);
    return 0;
}

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
public:
    // 可被具体实例类重写的抽象方法
    virtual void doing(){
        cout << "I am Base actor doing" << endl;
    };
};

// 继承抽象基类
class HTTPServer:public Base{
public:
    HTTPServer(const string& name){
        cout <<"Server name :" << name << endl;
    }
    virtual void doing(){
        cout << "I am HTTPServer actor doing" << endl;
    };
    
};
class HTTPSServer:public Base{
public:
    HTTPSServer(const string& name){
        cout <<"Server name :" << name << endl;
    }
    virtual void doing(){
        cout << "I am HTTPSServer actor doing" << endl;
    };
};
class TCPServer:public Base{
public:
    TCPServer(const string& name){
        cout <<"Server name :" << name << endl;
    }
    virtual void doing(){
        cout << "I am TCPServer actor doing" << endl;
    };
    
};
class QUICServer:public Base{
public:
    QUICServer(const string& name){
        cout <<"Server name :" << name << endl;
    }
    virtual void doing(){
        cout << "I am QUICServer actor doing" << endl;
    };
    
};
class UDPServer:public Base{
public:
    UDPServer(const string& name){
        cout <<"Server name :" << name << endl;
    }
    virtual void doing(){
        cout << "I am UDPServer actor doing" << endl;
    };
};

class WSServer:public Base{
public:
    WSServer(const string& name){
        cout <<"Server name :" << name << endl;
    }
};

// 简单工厂类
class Factory{
public:
    Base* actor = nullptr;
    Base* Create(const NetWork& net){
        switch (net) {
            case NetWork::HTTP:
                actor = new HTTPServer("http");
                break;
            case NetWork::HTTPS:
                actor = new HTTPSServer("https");
                break;
            case NetWork::QUIC:
                actor = new QUICServer("quic");
                break;
            case NetWork::TCP:
                actor = new TCPServer("tcp");
                break;
            default:
                actor = new Base();
                break;
        }
        return actor;
    }
    
    
};


int main1(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    // 创建工厂
    Factory* factory = new Factory();
    Base* actor = factory->Create(NetWork::HTTP);
    actor->doing();
    return 0;
}


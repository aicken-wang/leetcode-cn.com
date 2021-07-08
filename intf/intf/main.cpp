//
//  main.cpp
//  intf
//
//  Created by shunqing wang on 2021/4/23.
//

//#define _SVID_SOURCE
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

void func(){
    std::cout << "执行1" << std::endl;
    exit(0);
}

void func1() {
    std::cout << "执行2" << std::endl;
}
void func2(int argc, void* str) {
    std::cout << "str " << (char*)str << std::endl;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
//    _exit(-1);
//    exit(0);
    atexit(func);
    atexit(func1);
//    on_exit(func2,(void*)argv[0]); // MAC/Unix 上是不支持的 Unix
    
    std::cout << "hello" << std::endl;
    return 0;
}

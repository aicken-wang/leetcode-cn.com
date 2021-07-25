//
//  main.cpp
//  genRand
//
//  Created by shunqingwang on 2021/7/25.
//

#include <iostream>
#include <time.h>
#include <stdlib.h>
#define ZSKIPLIST_P 0.25
#define ZSKIPLIST_MAXLEVE 64
int zslRandomLevel(){
    int level =1;
    // 0xFFFF = 65535
    // rand()
    /*
     level = 1  1-p
     level = 2  p(1-p)
     level = n  p^n-1(1-p)
     redis的跳跃表期望层数是 1/(1-p) ~= 1.33
     */
    while(( random() & 0XFFFF) < ( ZSKIPLIST_P * 0XFFFF))
        level += 1;
    return (level < ZSKIPLIST_MAXLEVE)?level:ZSKIPLIST_MAXLEVE;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    srand(time_t(NULL));
    for(int i = 0; i < 100000; i++){
        std::cout <<"rand_"<< i << " = "<< zslRandomLevel() << std::endl;
    }
    return 0;
}

#include<iostream>
using namespace std;
int NumberOf1(int n){
    int count =0;
    while (n)
    {
        // 1010
        // 1001
        // 1000

        // 1000
        // 0111
        // 0000
        ++count;
        n = (n-1)&n;
    }
    return count;
    
}
// 32次
int NumberOf2(int n){
    int count =0;
    unsigned int flag = 1;
    while (flag) {
        if(n & flag)
            count++;
        flag = flag << 1;
    }
    return count;
}
int main(int argc, char** argv) {
    
    return 0;
}
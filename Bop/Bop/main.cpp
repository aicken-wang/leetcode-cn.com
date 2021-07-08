//
//  main.cpp
//  Bop
//
//  Created by shunqing wang on 2021/6/24.
//

#include <iostream>
#include <map>
#include <string>
using namespace std;
namespace OpEx {
    const int ADD = 1; // 加法
    const int SUB = 2; // 减法
    const int MUL = 3; // 乘法
    const int DIV = 4; // 除
    const int POW = 5; // 幂
    const int MOD = 6; // 模

}
map<string,int> option = {
     {"+", OpEx::ADD},
     {"-", OpEx::SUB},
     {"*",OpEx::MUL},
     {"/",OpEx::DIV},
     {"**",OpEx::POW},
     {"%",OpEx::MOD}
};

double myMul(int x, int N) {
        double ans = 1.0;
        double x_ = x;
        while (N > 0) {
            if (N % 2 == 1) {
                ans *= x_;
            }
            x_ *= x_;
            N /= 2;
        }
        return ans;
    }
int BinaryOp(int32_t a, const string &op, int32_t b, int32_t *result){
    if(!option.count(op)) return -1;
    switch(option[op]) {
        case OpEx::ADD: *result = a + b;
            break;
        case OpEx::SUB: *result = a - b;
            break;
        case OpEx::MUL: *result = a * b;
            break;
        case OpEx::DIV:{
            // panic
            if(b == 0) return -1;
            *result = a/b;
            break;
        }
        case OpEx::POW:{
            *result = b>= 0 ? myMul(a, b) : 1.0 / myMul(a, -b);
            break;
        }
        case OpEx::MOD:
            *result = a%b;
            break;
        default:
            cout << "I don't know..." << endl;
    }
    return 0;
}
int main(int argc, char** argv) {
    int32_t r = 0;
    cout << BinaryOp(1, "+", 1, &r) <<endl;
    cout <<  r << endl;
}

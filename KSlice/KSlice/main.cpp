//
//  main.cpp
//  KSlice
//
//  Created by shunqing wang on 2021/6/24.
//

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
int getIndex(string s1, string s2){
    int i =0,j = 0, k = 0;
    int len1 = (int)s1.length();
    int len2 = (int)s2.length();
    while(i <len1 && j < len2){
        if(s1[i] == s2[j]){
            i++;
            j++;
        }
        else {
            k++; //子串后移，比较后一个自串
            j = 0; //T子串从开始比较
            i = k; //后一个子串的首尾开始
        }
    }
    return k + len2;
    
}
int main(int argc, const char * argv[]) {
    string s1 = "adabcacyde";
    string s2 = "abc";
    int idx = getIndex(s1, s2);
    cout << idx <<endl;
    return 0;
}

//
//  main.cpp
//  max_len_str
//
//  Created by shunqing wang on 2021/5/31.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int max_len_substring(string &s) {
    if(s.empty()) return 0;
    int max = 0; // 最长的substr子字符串的长度
    int strLen = 0; // 字符串的长度
    vector<char> v; // 存储字符串的vector
    string::iterator item = s.begin();
    while(item != s.end()) {
        // 查询v里面有没有档期要插入的字符
        auto check = find(v.begin(),v.end(),*item);
        if(check == v.end()) {
            // 如果没有找到，就会返回最后一个元素
            v.emplace_back(*item);// 把这字符串放在v的最后面
            strLen++;//字符串的长度加一
        }
        else{
            // 字符串已经存在vector中
            if(max < strLen)// 更新一个max
                max = strLen;
            // 把当前重复的字符串和它之前的所有字符全部清除
            v.erase(v.begin(),check+1);
            //将字符存入vector里
            v.emplace_back(*item);
            // 获取容器的大小
            strLen = (int)v.size();
        }
        item++;
    }
    if(max < strLen) max = strLen;
    return max;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

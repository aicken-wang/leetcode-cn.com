//
//  main.cpp
//  LFUCache
// Least Frequently Used
//
//  Created by shunqing wang on 2021/6/18.
/*
 LFU 算法根据数据的历史访问频率来淘汰数据，其核心思想 如果数据过去被访问多次那么
将来被访问的频率也更高 28定律
 LFU的每一个数据块都有一个引用计数，所有数据块按照引用计数排序，具有相同引用计数的数据块
 则按照时间排序
 1.新加入数据插入到队列尾部
 2.队列中的数据被访问后，引用计数增加，队列重新排序
 3.当需要淘汰数据时，将已经排序的列表最后的数据块删除
 */
#include <iostream>
#include <unordered_map>
#include <map>
#include <stdlib.h>
#include <stdio.h>
#include <set>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

//
//  main.cpp
//  longestSubstring
//
//  Created by shunqing wang on 2021/6/15.
//

#include <iostream>
#include <string>
#include <unordered_set>
#include <set>
using namespace std;
/*
 3. 无重复字符的最长子串
 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 输入: s = "abcabcbb"
 输出: 3
 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 */
int lengthOfLongestSubstring(string& s){
    int ans = 0;
    unordered_set<char> hashset;
    int n = (int)s.size();
    // 设置右边界
    int rk = -1;
    for(int i = 0; i < n; i++){
        if(i != 0){
            // 子串中原重复的字符。
            hashset.erase(s[i - 1]);
        }
        while(rk + 1 < n && !hashset.count(s[rk + 1])){
            // 移动 rk 缓存子串
//          rk++;
            hashset.insert(s[++rk]);
        }
        // 计算不重复子串的长度
        int offset = rk - i + 1;
        ans = offset>ans?offset:ans;
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    string s = string("abcabcbb");
    cout << "原串 "<< s << endl;
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}

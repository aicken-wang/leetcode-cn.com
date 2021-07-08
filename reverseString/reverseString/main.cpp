//
//  main.cpp
//  reverseString
//
//  Created by shunqing wang on 2021/5/19.
//

#include <iostream>
#include <vector>
void reverseString(std::vector<char> &s) {
    int n = (int)s.size();
    int idx = 0;
    while(idx < n){
        // 记住start
        int start = idx;
        //跳过单词，找分隔符‘ ’
        while(idx < n && s[idx] !=' ') idx++;
        // 遇到空格
        int left = start,right = idx - 1;
        while(left < right){
            std::swap(s[left],s[right]);
            left++;
            right--;
        }
        // 跳过空格
        while(idx < n && s[idx] == ' ') idx++;
        
    }
    for(auto c:s){
        std::cout << c;
    }
    std::cout<< std::endl;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<char> cs ={'I',' ','A','M',' ','S','T','U','D','Y'};
    reverseString(cs);
    for(auto c:cs){
        std::cout << c;
    }
    std::cout<< std::endl;
    return 0;
}

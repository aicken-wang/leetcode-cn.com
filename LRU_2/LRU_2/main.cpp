//
//  main.cpp
//  LRU_2
//
//  Created by shunqing wang on 2021/6/19.
//

#include <iostream>
#include <list>
#include <unordered_map>
#include <unistd.h>
using namespace std;

class LRUCache{
private:
    // cap
    int m_cap;
    list<pair<int,int>> m_list;
    unordered_map<int, list<pair<int,int>>::iterator> hashmap;
public:
    LRUCache(int capacity):m_cap(capacity){};
    int get(int key){
        if(!hashmap.count(key)) return -1;
        auto node = *hashmap[key];
        m_list.erase(hashmap[key]);
        m_list.push_front(node);
        hashmap[key] = m_list.begin();
        return node.second;
    }
    void put(int key, int value) {
        // 不存在的元素
        auto itor = hashmap.find(key);
        if(itor == hashmap.end()){
            // 是否超过容量
            if(m_list.size() == m_cap)
            {
                // 淘汰元素
                auto node = m_list.back();
                m_list.pop_back();
                hashmap.erase(node.first);
            }
        }
        else {
            // 只需要删除list
            m_list.erase(itor->second);
        }
        // 新元素
        m_list.push_front({key,value});
        hashmap[key] = m_list.begin();
    }
    
    
};
// 反转字符串
char* reverseChar(char *str){
    // 空 return
    if(!str || *str == '\0') return str;
    char *start = str;
    char *end = str;
    while (*end != '\0') {
        //cout << *end << endl;
        ++end;
    }
    // if(*end == '\0') cout << "kong"<< endl;
    // while 只有当前为空才会结束 --
    end--;
    while(start < end){
        swap(*start,*end);
        start++;
        end--;
    }
    return str;
}
char* strReverseEx(char *str) {
    if(!str || *str == '\0') return str;
    // 整体反转
    str = reverseChar(str);
    cout << "str "<< str <<endl;
    char *start = str;
    char *end = str;
    while(1) {
        //
        if(*end == ' '|| *end == ',') {
            *end = '\0';
            reverseChar(start);
            *end = ' ';
            start = end + 1;
            
        }
        // 最后一次反转
        if(*end == '\0') {
            reverseChar(start);
            break;
        }
        end++;
    }
    cout << "print(str)> " << str <<endl;
    return str;
}
void reverseStrEx(char *str,int start, int end){
    while(start < end){
        swap(*(str + start),*(str + end));
        start++;
        end--;
    }
}
char* leftRotateString(char* str, int n){
    int len = 0;
    char *strlen = str;
    if(!str || *str == '\0') return str;
    while(*strlen != '\0'){
        len++;
        strlen++;
    }
    cout << "len " << len << endl;
    if(n > 0 && n < len) {
        int start1 = 0;
        int end1 = n - 1;
        int start2 = n;
        int end2 = len -1;
        // 反转1
        reverseStrEx(str,start1,end1);
        cout << "1 -> "<< str <<endl;
        reverseStrEx(str, start2, end2);
        cout << "2 -> " << str <<endl;
        reverseStrEx(str, start1, end2);
        cout << "end ->" << str <<endl;
    }
    return str;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    LRUCache* lru = new LRUCache(2);
    lru->put(1,1);
    lru->put(2, 2);
    lru->put(3, 3);
    cout << lru->get(1) << endl;
    cout << lru->get(3) << endl;
    lru->put(4, 4);
    cout << lru->get(2)<< endl;
    char str[] = "hello world ! I'm Study...\0 hee";
    cout << reverseChar(str) << endl;
    char str0[] = "welcome,to,my,blog";
    cout <<strReverseEx(str0) << endl;
    char str1[] = "hello world  ! I'm Study...\0 hee";
    strReverseEx(str1);
    char str2[] = "abcdefgh";
    leftRotateString(str2, 2);
 
    return 0;
}

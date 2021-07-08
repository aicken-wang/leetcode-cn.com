//
//  main.cpp
//  LRUCache
//
//  Created by shunqing wang on 2021/4/4.
//

#include <iostream>
#include <unordered_map>
#include <list>
#include <ctime>
using namespace std;

class LRUCache {
private:
    // 缓存的容量
    int cap;
    // 缓存map
    unordered_map<int,list<pair<int,int>>::iterator> m_hashmap;
    // 双向链表
    list<pair<int,int>> m_list;
public:
    // 构造函数
    LRUCache(int capacity):cap(capacity){}
  
    // get 取值
    int get(int key){
        //不存在返回 -1
        auto item = m_hashmap.find(key);
        if(item == m_hashmap.end()) return -1;
        // 若存在需要更新到链表头部
        auto kv = *item->second;
        m_list.erase(item->second);
        //插入 node
        m_list.push_front(kv);
        // 更新 node
        m_hashmap[key] = m_list.begin();
        return kv.second;
    }
    // put 存值
    void put(int key, int val){
        // lru 算法是 不在map中且没有超过cap就是一个插入新值
        // 不在map中但是元素的个数超过了cap，需要先删除最后一个元素和map中对应的元素。
        // 在map中需要先把list的元素在去插入list和map中
        auto item = m_hashmap.find(key);
        if(item == m_hashmap.end()) {
            // 判断元素是否已经超过了cap
            if(cap == m_list.size()) {
                //删除map中的元素和list中的元素
                auto elem = m_list.back();
                // 删除list elem
                m_list.pop_back();
                m_hashmap.erase(elem.first);
            }
        }
        else {
            // 删除list
            m_list.erase(item->second);
        }
        // 插入新的元素
        m_list.push_front(pair<int,int>(key,val));
        m_hashmap[key] =m_list.begin();
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
//    srand(time_t(0));
//    for(int i =0; i <10; i++){
//        std::cout << rand() %10 << std::endl;
//    }
    LRUCache *lru = new LRUCache(2);
    std::cout << lru->get(1)<< std::endl;
    lru->put(1,1);
    lru->put(2,2);
    lru->put(3,3);
    std::cout << lru->get(1)<< std::endl;
    delete lru;
    return 0;
}

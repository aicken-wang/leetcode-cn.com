/*
#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
class LRUCache
{
private:
    int cap;
    unordered_map<int,list<pair<int,int>>::iterator> hashMap;
    list<pair<int,int>> mList;
public:
    LRUCache(int capacity):cap(capacity){}
    void put(int key,int value = 0){
        auto item = hashMap.find(key);
        if(item == hashMap.end())
        {
            if(cap == mList.size())
            {
                //淘汰元素
                pair<int,int> item = mList.back();
                mList.pop_back();
                hashMap.erase(item.first);
            }
        }
        else {
            mList.erase(hashMap[key]);
        }
        // 插入对头
        mList.push_front({key,value});
        hashMap[key] = mList.begin();
    }
    int get(int key)
    {
        unordered_map<int,list<pair<int,int>>::iterator>::iterator itor = hashMap.find(key);
        if(itor == hashMap.end())
        {
            cout << "not found key:["<< key << "] please use \"lru.put(key,value)\" add  key and value."<<endl;
            return -1;
        }
        pair<int,int> item = *itor->second;
        mList.push_front(item);
        hashMap[key]= mList.begin();
        return item.second;
        
    }
    void print()
    {
        cout << "lru.print show all element." << endl;
        if(mList.empty()) {
            cout << "container is empty." << endl;
            return;
        }
        int idx = 0;
        for(auto elem:mList) {
            ++idx;
            cout <<"idx:"<< idx << " key:["<< elem.first << "] value:[" << elem.second << "]"<< endl;
        }
        cout << endl;
    }
};
int main(int argc,char** argv) {
    LRUCache lru(2);
    cout <<"lru.get(1) value:" <<  lru.get(1) << endl;
    lru.print();
    lru.put(1,1);
    lru.print();
    cout <<"lru.get(1) value:" <<  lru.get(1) << endl;
    lru.print();
    lru.put(1, 2);
    lru.print();
    lru.put(2,2);
    lru.print();
    lru.put(3,3);
    cout <<"lru.get(1) value:" <<  lru.get(1) << endl;
    
    return 0;
}
*/
#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class LRUCache{
private:
    int cap;
    list<pair<int,int> > mList;
    unordered_map<int,list<pair<int,int> >::iterator > hashMap;
public:
    LRUCache(int capacity):cap(capacity){}
    int get(int key) {
        unordered_map<int,list<pair<int,int> >::iterator >::iterator itor = hashMap.find(key);
        if(itor == hashMap.end()) return -1;
        // 移动元素到head
        pair<int,int>  item = *itor->second;//*hashMap[key];
        hashMap.erase(key);
        mList.push_front(item);
        hashMap[key] = mList.begin();
        return item.second;
    }
    void put(int key, int value) {
        unordered_map<int,list< pair<int,int> >::iterator >::iterator itor = hashMap.find(key);
        if(itor == hashMap.end()) {
            // drop tail element
            if(mList.size() == cap) {
                // 淘汰尾部元素
                pair<int,int>  item = mList.back();
                mList.pop_back();
                hashMap.erase(item.first);
            }
        }
        else {
            mList.erase(itor->second);
        }
        pair<int,int> elem = pair<int,int>(key,value);
        mList.push_front(elem);
        hashMap[key] = mList.begin();
    }

};
int main(int argc, char** argv) {
    LRUCache lru = LRUCache(2);
    lru.put(1,2);
    lru.put(2,3);
    lru.put(3,4);
    cout << lru.get(1) << endl;
    cout << lru.get(3) << endl;
    return 0;
}

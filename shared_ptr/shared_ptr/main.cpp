//
//  main.cpp
//  shared_ptr
//
//  Created by shunqing wang on 2021/6/2.
//

#include <iostream>
template<typename T>
class SmartPtr {
private:
    T* ptr;
    int* count;
    void reset(){
        if(count) {
            (*count)--;
            if(*count == 0){
                delete ptr;
                delete count;
            }
        }
    }
public:
    SmartPtr():ptr(nullptr),count(nullptr){}
    explicit SmartPtr(T* t):ptr(t){
        count = nullptr;
        if(ptr){
            count = new int(1);
        }
    }
    explicit SmartPtr(const SmartPtr& rhs){
        ptr = rhs.ptr;
        count = rhs.count;
        if(count){
            (*count)++;
        }
    }
    ~SmartPtr(){
        // delete
        reset();
    }
    // COPY CUST
    SmartPtr& operator=(const SmartPtr& rhs){
        if(this == &rhs){
            return *this;
        }
        reset();
        ptr= rhs.ptr;
        count = rhs.count;
        if(count){
            (*count)++;
        }
        return *this;
    }
    SmartPtr& operator*(){
        return *this;
    }
    T* operator->(){
        return ptr;
    }
    T* get(){
        return ptr;
    }
    int use_count() const{
        return count?*count:0;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    SmartPtr<int> ptr(new int(1));
    SmartPtr<int> ptr2;
    ptr2 = ptr;
    std::cout << ptr.use_count()<< std::endl;
    return 0;
}

//
//  main.cpp
//  singleLinkLoop
//
//  Created by shunqing wang on 2021/4/5.
//

#include <iostream>
#include <vector>
template<typename T>
struct Node {
    T data;
    Node* next;
    Node(int val):data(val),next(nullptr){}
};
/*
 解题思路: 判断一个链表是否有环，实用快慢指针。遍历一次，当快指针追上慢指针即存在环，
 当快指针为空时，说明链表不存在环。
 */
bool isChecked(Node<int>* head) {
    if(head == nullptr || head->next == nullptr) return false;
    Node<int>* fast = head->next;
    Node<int>* slow = head;
    while(fast != nullptr && fast->next != nullptr){
        if(slow == fast){
            return true;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    return false;
    
}

int main(int argc, const char * argv[]) {

    std::cout << __cplusplus  << "__FILE__ " <<__FUNCTION__ << __LINE__ << std::endl;
    
    // insert code here...
    Node<int>* l1 = new Node<int>(1);
    Node<int>* l2 = new Node<int>(2);
    Node<int>* l3 = new Node<int>(3);
    l1->next = l2;
    l2->next = l3;
    //l3->next = l1;
    std::cout <<((isChecked(l1)==true)?"true":"false") << std::endl;
    while (l1 != nullptr) {
        Node<int>* tmp = l1->next;
        if(l1) delete l1;
        l1 = tmp;
    }

    return 0;
}

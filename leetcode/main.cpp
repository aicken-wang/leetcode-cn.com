//
//  main.cpp
//  leetcode
//
//  Created by shunqing wang on 2021/3/21.
//

#include <iostream>
#include <random>
#include <time.h>
#include <stdlib.h>
using namespace std;
#include <stdio.h>
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
};
char buf[] = {0,1,2,3,4};
char buf2[] =  {'0','1','2','3','4'};
ListNode* addTwoSum(ListNode* l1, ListNode* l2) {
    // 创建头节点
    ListNode* head = new ListNode(-1);
    ListNode* cur = head;
    int sum = 0;
    bool carry = false;
    while(l1!= nullptr || l2 != nullptr) {
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }
        
        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }
        if(carry) {
            sum += 1;
        }
        cur->next = new ListNode(sum%10);
        carry = (sum >= 10)?true:false;
        sum = 0;
        cur = cur->next;
    }
    if(carry) cur->next = new ListNode(1);
    return head->next;
    
}
int main(int argc, const char * argv[]) {
    srand(time_t(0));
    default_random_engine e;
    uniform_int_distribution<unsigned> u(0,10);
    for(int i = 0; i < 10; ++i) {
        cout << rand()%10 << endl;
    }
    // 2 -> 1 -> 3
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(1);
    l1->next->next = new ListNode(3);
    // 3 -> 2 -> 4
    ListNode* l2 = new ListNode(3);
    l2->next = new ListNode(2);
    l2->next->next = new ListNode(4);
    // 312 + 423 = 735
    ListNode* res = addTwoSum(l1,l2);
    while (res != nullptr) {
        cout << res->val;
        if(res->next != nullptr)
            cout << " -> ";
        else
            cout << endl;
        res =  res->next;
    }
    return 0;
}

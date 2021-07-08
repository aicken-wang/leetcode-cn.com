#ifndef _LIST_HEAD_
#define _LIST_HEAD_
#include <iostream>
using namespace std;
typedef struct ListNode {
    int value;
    ListNode* next;
    ListNode(int value):value(value),next(nullptr) {}
    ListNode(int value, ListNode* ptr):value(value),next(ptr) {}
} *pListNode;

void Println(ListNode* head){
    cout << "---------- show cur list element Println begin ---------- " <<endl;
    ListNode* node = head;
    while(node != nullptr) {
        cout << node->value << " ";
        node = node->next;
    }
    cout <<  "\n---------- Println end ---------- "<< endl;
}
void AddToTail(ListNode** head,int val) {
    cout << "添加元素 " << val << endl;
    ListNode* pNode = new ListNode(val);
    if(*head == nullptr) {
        cout << "head is empty" << endl;
        *head = pNode;
    } else {
        // 追加到尾部
        ListNode* tmp = *head;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        // 挂载node节点
        tmp->next = pNode;
       
    }

}
// 删除节点
void RemoveNode(ListNode** head, int val) {
    if(head == nullptr|| *head == nullptr) return;
    ListNode* pNodeToDeleted = nullptr;
    if((*head)->value == val) {
        // 头结点就是删除元素
        pNodeToDeleted = *head;
        *head= (*head)->next;
    } else {
        ListNode* node = *head;
        // 找到val的前一个节点或遍历到链表尾部没有找到val
        while (node->next!=nullptr&& node->next->value != val)
        {
            node = node->next;
        }
        // 找到val
        if(node->next!=nullptr&& node->next->value == val) {
            pNodeToDeleted = node->next;
            // 跳跃一个节点 当前的下一个节点指向下下个节点
            node->next = node->next->next;
        }
        // 删除节点
        if( pNodeToDeleted != nullptr) {
            delete pNodeToDeleted;
            // 避免悬空指针
            pNodeToDeleted = nullptr;
        }
        
    }
}
#endif // _LIST_HEAD_
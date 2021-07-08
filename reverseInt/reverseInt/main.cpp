//
//  main.cpp
//  reverseInt
//
//  Created by shunqing wang on 2021/4/5.
//

#include <iostream>
#include <vector>
class LinkedList{
private:
    struct ListNode{
        int data;
        ListNode* next;
        ListNode(int value):data(value),next(nullptr){}
    };
    ListNode* head;
public:
    LinkedList(int arr[],int n){
        head = new ListNode(-1);
        ListNode *node = head;
        for(int i=0; i<n; i++) {
            node->next= new ListNode(arr[i]);
            node = node->next;
        }
    }
    ~LinkedList(){
        // TODO
        while (head != nullptr) {
            ListNode *node = head;
            std::cout << node->data;
            if(node) delete node;
            head = head->next;
        }
        std::cout << std::endl;
        
    }

    void PrintList(){
        ListNode* node = head;
        while (node->next != nullptr) {
            node = node->next;
            std::cout << node->data<< std::endl;
        }
        std::cout << std::endl;
        
    }
    void reorderList() {
        // 判断链表是否为空
        if(head == nullptr) return;
        // 使用容器记录链表的所有元素
        std::vector<ListNode*> vec;
        ListNode* ptr = head;
        while(ptr != nullptr) {
            vec.emplace_back(ptr);
            ptr = ptr->next;
        }
        size_t l = 0, r = vec.size() - 1;
        /*
        ** 这个直接操作vector容器的元素使得l的next关联r，r的next关联l就行。否则就不知道怎么修改指针了。
        */
        while(l < r) {
            // l关联 r  l++ ==> L0 -> Ln
            vec[l++]->next = vec[r];
            //退出条件
            if(l == r) break;
            // r  关联 l r--
            vec[r--]->next = vec[l];
        }
        // l 是最后一个链表元素
        vec[l]->next = nullptr;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[] = {1,2,3,4,5,6};
    LinkedList list = LinkedList(arr,sizeof(arr)/sizeof(arr[0]));
    
    list.PrintList();
    list.reorderList();
    list.PrintList();
    std::cout << "Hello, World!\n";
    return 0;
}

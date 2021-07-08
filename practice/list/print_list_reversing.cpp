#include "list_head.h"
#include <stack>

void PrintListReversing(ListNode *head) {
    stack<ListNode*> stk;
    ListNode* pNode = head;
    while(pNode !=nullptr) {
        stk.push(pNode);
        pNode = pNode->next;
    }
    while(!stk.empty()) {
        cout << stk.top()->value <<" ";
        stk.pop();
    }
    cout << endl;
}
void RecursiveList(ListNode* head) {
    // 递归终止条件
    if (head == nullptr) return; 
    //先到next 再打印
    RecursiveList(head->next);
    cout << head->value << " ";

}
int main(int argc, char** argv) {
    ListNode* myList = nullptr;
    AddToTail(&myList,1);
    AddToTail(&myList,2);
    AddToTail(&myList,3);
    AddToTail(&myList,4);
    // print all element
    Println(myList);
    // delete element
    RemoveNode(&myList,3);
    // show delete after all element
    Println(myList);
    
    PrintListReversing(myList);
    cout << "RecursiveList:";
    RecursiveList(myList);
    cout << endl;
    return 0;
}
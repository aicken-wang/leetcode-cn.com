#include <iostream>
#include <vector>
using namespace std;
struct BTreeNode {
    int value;
    BTreeNode* left;
    BTreeNode* right;
    BTreeNode(int value) : value(value), left(nullptr),right(nullptr){}
};
// 有一点儿问题。
/**
 * @brief 
 * 
 * @param  startPreOrderItor 前序首元素
 * @param  endPreOrderItor   前序尾元素
 * @param  startInOrderItor  中序首元素
 * @param  endInOrderItor    中序尾元素
 * @return BTreeNode* 
 */
BTreeNode* BuildTree(vector<int>::iterator startPreOrderItor, 
                    vector<int>::iterator endPreOrderItor, 
                    vector<int>::iterator startInOrderItor,
                    vector<int>::iterator endInOrderItor) 
{
    // 通过前序获取根
    int rootValue = *startPreOrderItor;
    BTreeNode* root = new BTreeNode(rootValue);
    // 全部元素遍历完
    if (startPreOrderItor == endPreOrderItor)
    {
        // 中序的起始 == 中序的结束 并且
        cout << *startPreOrderItor << " " << *startInOrderItor << endl;
        if(startInOrderItor == endInOrderItor && *startPreOrderItor == *startInOrderItor)
        return root;
        else 
        cout << "1 invalid input...\n";
    }
    // 在中序遍历序列中找根节点的值
    vector<int>::iterator rootInOrderItor = startInOrderItor;
    while(rootInOrderItor <= endInOrderItor 
          && *rootInOrderItor != rootValue ) ++rootInOrderItor;
    if(rootInOrderItor == endInOrderItor && *rootInOrderItor != rootValue)
        cout << "2 invalid input...";
    int leftLen = rootInOrderItor - startInOrderItor;
    // len - 1 
    vector<int>::iterator leftChildPreOrderEnd = startPreOrderItor + leftLen;
    if(leftLen > 0) {
        // 左子树
        root->left = BuildTree(++startPreOrderItor, leftChildPreOrderEnd,
                              startInOrderItor, --rootInOrderItor);
    }
    // 一个左一个右
    if (leftLen < endPreOrderItor - startPreOrderItor) {
        // 构建右子树
        root->right = BuildTree(++leftChildPreOrderEnd,endPreOrderItor,
                                ++rootInOrderItor,endInOrderItor);
    }
    return root;  
}
/**
 * @brief 
 * 
 * @param  preOrderNums     前序数组
 * @param  inOrderNums      中序数组
 * @return BTreeNode* 
 */
BTreeNode* Construct(vector<int>& preOrderNums,vector<int>& inOrderNums) {
    int prelen = preOrderNums.size();
    int inlen = inOrderNums.size();
    if(prelen <=0 || inlen <=0 || prelen != inlen ) return nullptr;
    return BuildTree(preOrderNums.begin(),--preOrderNums.end(),inOrderNums.begin(),--inOrderNums.end());

}
void PreOrder(BTreeNode* root) {
    if(root == nullptr) return;
    cout << root->value << " " ;
    PreOrder(root->left);
    PreOrder(root->right);
}
void InOrder(BTreeNode* root) {
    if (root == nullptr) return;
    InOrder(root->left);
    cout  << root->value << " ";
    InOrder(root->right);
}
int main(int argc, char** argv) {
    vector<int> nums1{1,2,4,7,3,5,6,8};
    vector<int> nums2{4,7,2,1,5,3,8,6};
    BTreeNode* root = Construct(nums1,nums2);
    PreOrder(root);
    std::cout << endl;
    InOrder(root);
    std::cout << endl;
    return 0;
}
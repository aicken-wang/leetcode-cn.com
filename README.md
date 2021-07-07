[1. 两数之和 ](https://leetcode-cn.com/problems/two-sum/)

- C++版本
-  使用hash table 时间复杂度O(1) 空间复杂度O(1)

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     vector<int> res;
     int len = nums.size();
     if(len < 2) return res;
     unordered_map<int,int> hashmap;
     for( int i = 0; i < len; i++){
         auto itor = hashmap.find(nums[i]);
         if(itor == hashmap.end()) {
             // 保存 target - nums[i]
             hashmap[target - nums[i]] = i;
         } else {
             // 匹配的数据
             res.emplace_back(hashmap[nums[i]]);
             res.emplace_back(i);
         }
     }
     return res;
    }  
};
```

- Go版本

```go
func twoSum(nums []int, target int) []int {
     numMap := make(map[int]int)
     for index, num := range nums {
         /*判断target-num在numMap中, ok为 true说明满足条件
            return
         */
        if i, ok := numMap[target - num]; ok{
            return []int{i,index}
        }
        //存入 numMap中
        numMap[num] = index
     }
     /*not found target*/
     return nil
}
```

[2. 两数相加 ](https://leetcode-cn.com/problems/add-two-numbers/)

- C++版本

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 定义sum carry 
        int sum = 0, carry = 0;
        ListNode* temp = new ListNode(0);
        while(l1 != nullptr || l2 != nullptr) {
            int x  = (l1 != nullptr?l1->val:0);
            int y = (l2 !=nullptr?l2->val:0);
            sum = x + y + carry;
            ListNode* node = new ListNode(sum%10);
            carry = sum/10; 
            temp->next = node;
            // 递增
            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
            temp = temp->next;
        }
        if(carry > 0) {
            ListNode* node = new ListNode(carry);
            temp->next = node;
        }
        ListNode* res = temp->next;
        delete temp;
        temp = nullptr;
        return res;
    }
};
```

- Go版本

```
func addTwoNumbers(l1, l2 *ListNode) (head *ListNode) {
    var tail *ListNode
    carry := 0
    // 当l1 或 l2 非空时
    for l1 != nil || l2 != nil {
        n1, n2 := 0, 0
        if l1 != nil {
            n1 = l1.Val
            l1 = l1.Next
        }
        if l2 != nil {
            n2 = l2.Val
            l2 = l2.Next
        }
        sum := n1 + n2 + carry
        sum, carry = sum%10, sum/10
        if head == nil {
            head = &ListNode{Val: sum}
            tail = head
        } else {
            tail.Next = &ListNode{Val: sum}
            tail = tail.Next
        }
    }
    if carry > 0 {
        tail.Next = &ListNode{Val: carry}
    }
    return
}
```





#  寻找丢失的数字

```c++

class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        long sum = 0, n = nums.size();
        // 累加
        for (auto &a : nums) {
            sum += a;
        }
        // 1~ n的和 - sum 就是丢失的数
        return (int)(n * (n + 1) * 0.5 - sum);
    }
};
// 使用bit位^当前的index两次后会抵消最后的结果就是丢失的数据,需要先排序nlog(n)，与leetcode找只出现一个元素思路一样
class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            res ^= nums[i] ^ (i + 1);
        }
        return res;
    }
};
```

## 反转二叉树

```c++
# 递归
class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
    	// 递归终止条件
        if (!root) return;
        // 临时变量保存 left 
        TreeNode *tmp = root->left;
        // 交换
        root->left = root->right;
        root->right = tmp;
        // 递归左子树
        invertBinaryTree(root->left);
        // 递归右子树
        invertBinaryTree(root->right);
    }
};

# 非递归需要用queue来辅助记录左右节点
// Non-Recursion
class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
    	// 异常判断
        if (!root) return;
        // 辅助queue记录左右节点
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
        	// 先交换跟的左右子树
            TreeNode* node = q.front(); 
            q.pop();
            // 交换
            TreeNode *tmp = node->left;
            node->left = node->right;
            node->right = tmp;
            // 层层交换左子树
            if (node->left) q.push(node->left);
            // 层层交换右子树
            if (node->right) q.push(node->right);
        }
    }
};
```


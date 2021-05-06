//
//  main.cpp
//  getleastNumbers
//
//  Created by shunqing wang on 2021/5/6.
//
/*
输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。
示例 1：
输入：arr = [3,2,1], k = 2 输出：[1,2] 或者 [2,1] 示例 2：
输入：arr = [0,1,2,1], k = 1 输出：[0]
限制：
0 <= k <= arr.length <= 10000 0 <= arr[i] <= 10000
计数排序 解题思路:
初始化，计数数组的下标count都是等于0.，意味着每个元素都出现了0次。
第一个元素2，放在下标是2的位置，由于只出现了一次，所以下标为2的count值+1.
第2个元素2，放在下标是2的位置，计数count再进行+1 变成2，代表2出现了2次。
第3个元素1，放在下标是1的位置，下标为1的计数count进行+1变成1，代表1出现了1次。
第4个元素0，放在下标是0的位置，下标为0的计数count进行+1变成1，代表0出现了1次。
第5个元素1，放在下标是1的位置，下标为1的计数count进行+1变成2，代表1出现了2次。
第6个元素5，放在下标是5的位置，下标为5的计数count进行+1变成1，代表5出现了1次
接下来针对计数数组进行处理，遍历计数数组，为了方便理解把原数组清空。
遍历索引为0，计数数组值是1，代表0出现1次，所以让0占位原数组的1位。
遍历索引为1，计数数组值是2，代表1出现2次，所以让1占位原数组的2位。
遍历索引为2，计数数组值是2，代表2出现2次，所以让2占位原数组的2位。
遍历索引为3，计数数组值是0，代表3出现0次，所以不占位
遍历索引为4，计数数组值是0，代表4出现0次，所以不占位
遍历索引为5，计数数组值是1，代表5出现1次，所以5占位原数组1位。
到这里。原数组变得有序了！

*/
#include <iostream>
#include <vector>
class Solution {
/*
思路:
1、开辟数组
2、对传入数组元素计数
3、对数组排序
*/
public:
std::vector<int> getLeastNumbers( std::vector<int>& arr, int k) {

    // 临时数组
    std::vector<int> temp(10000);
    for(auto data: arr) {
        temp[data]++;
    }
    // 结果数组
    std::vector<int> result;
    int count = 0; // 计数
    for(int i = 0; i < temp.size(); ++i) {
        if(count >= k) break;
        if(temp[i] > 0) {
            // 元素存在原数组中
            while(temp[i]--){
                result.emplace_back(i);
                count++; // 不能超过 k 个
            }

        }
    }
    result.resize(k);
    return result;

}
};
int main(int argc, char** argv)
{
    std::vector<int> arr{0,5,2,3,1,1,2};
    Solution s;
    std::vector<int> res = s.getLeastNumbers(arr,3);
    for(auto data:res) std::cout << data << std::endl;
    return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    //a + b == -c
    //1. n^3 for loop
    //2. n^2 hash
    //3. 左右指针推进
    //直接用double point
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        //先排序
        sort(nums.begin(),nums.end());
        int len =nums.size();
        //通过i+ len-1之间的双指针之和与-nums[i]比较
        for(int i = 0; i < len - 2; i++) 
        {
            //避免 i和i-1项重复则跳过
            if(i==0 || (i > 0 && nums[i] != nums[i-1]))
            {
                //定义初始变量 lower hight  point
                int left = i+1, right = len -1, sum = 0 - nums[i];
                //一次变量终止条件
                while(left < right) {
                    // 相等
                    if(sum == nums[left] + nums[right]) {
                        vector<int> tmp{nums[i], nums[left], nums[right]};
                        res.push_back(tmp);
                        //跳过重复项
                        while(left < right && nums[left] == nums[left + 1]) left++;
                        while(left < right && nums[right] == nums[right - 1]) right--;
                        left++;
                        right--;
                    }
                    //大于
                    else if(sum > nums[left] + nums[right]) left++;
                     //小于
                    else right--;
                }
                
            }
        }
        return res;
    }
};
// 请使用高版本的c++编译器
int main(int argc, char** argv) 
{
  vector<int> test_nums {-1, 0, 1, 2, -1, -4};
  Solution s;
  vector<vector<int>> result = s.threeSum(test_nums);
    for(auto items : result){
        for(auto item : items){
             cout << item << "\t";
        }
        cout << endl;
    }
  return 0;
}

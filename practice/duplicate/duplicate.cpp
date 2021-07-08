#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 查找数字中是否有重复元素
 * 
 * @param nums 
 * @param duplication 
 * @return true 
 * @return false 
 */
bool duplicate(vector<int> nums,int &duplication){
    int len = nums.size();
    if(len <= 0) return false;
    // 范围在0 - (len - 1)
    for(int data : nums){
        if( data < 0 || data >= len-1 ) return false;
    }
    // 交换，元素值和下标是否相等，不相等就交换，知道出现对应下标的值和下标相等且交换元素和下标相等就出现了重复元素
    for(int i=0; i <len; i++) {
        if (nums[i] == nums[nums[i]]) {
            duplication = nums[i];
            return true;
        }
        // 交换 下标的值与对应的值的下标的元素
        swap(nums[i],nums[nums[i]]);
    }
    return false;
}
int main(int argc, char** argv) {
    vector<int> nums{2,3,1,0,2,5,3};
    int dup = -1;
    bool isOk = duplicate(nums,dup);
    if(isOk) {
        cout << "duplication value :" << dup << endl;
    }
    return 0;
}
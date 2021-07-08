#include <iostream>
#include <vector>
using namespace std;
void ReorderOddEven(vector<int>& nums) {
    int len = nums.size();
    if (len <= 1) return;
    int left = 0;
    int right = len - 1;
    while(left < right) {
        // begin 找到偶数 (nums[left]& 0x1) != 0 找到奇数继续找
        // while(left < right && (nums[left] & 0x1) !=0) 
        while(left < right && (nums[left]%2) != 0) 
        {
            left++;
        }
        // end 再找到奇数 0x01 == 0 继续找
        //while(left < right && (nums[right]& 0x1) == 0)
        while(left < right && (nums[right]%2) == 0 )
        {
            right--;
        }
        if(left < right){
            std::swap(nums[left], nums[right]);
        }
    }

}
int main(int argc, char**argv) {
    vector<int> nums{1,2,3,4,5};
    ReorderOddEven(nums);
    for(auto data: nums) {
        cout << data << " ";
    }
    cout << endl;
    return 0;

// gcc reorder_odd_even.cpp  --std=c++11 
// clang++ reorder_odd_even.cpp  --std=c++11 
}
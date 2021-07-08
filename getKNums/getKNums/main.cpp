//
//  main.cpp
//  getKNums
//
//  Created by shunqing wang on 2021/6/5.
//

#include <iostream>
#include <vector>
#include <queue>          // std::priority_queue
#include <functional>     // std::less
using namespace std;

int getKNum(vector<int>& nums, int k){
    int n = (int)nums.size();
    if(n < k) return -1;
    sort(nums.begin(),nums.end());
    return nums[k];
}

int getKNum2(vector<int>& nums, int k){
    int n = (int)nums.size();
    if(n < k) return -1;
    std::priority_queue<int,vector<int>,less<int>> pq;
    for(int i=0; i < k; i++){
        pq.push(nums[i]);
        // pair<int,int>
    }
    for(int i =k; i< n; i++){
        if(nums[i] < pq.top()){
            pq.pop();
            pq.push(nums[i]);
        }
    }
    return pq.top();
}
int main(int argc,char** argv){
    vector<int> nums = {6,6,6,6,6,6};
    cout << getKNum2(nums,6) << endl;
    return 0;
}

//
// Created by Zhuoer LIU on 2025-12-01.
//
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> results;
        for(int i=0; i<nums.size()-2; i++){
            if(i>0 && nums[i]==nums[i-1]) continue; //如果当前 nums[i] 和前一个相同，直接跳过，因为相同元素已经被处理过了
            int j=i+1, k=nums.size()-1;
            while(j<k){
                int curr_sum = nums[i]+nums[j]+nums[k];
                if(curr_sum<0){
                    j++;
                }else if (curr_sum>0){
                    k--;
                }else{
                    // j/k的去重发生在找到有效解后
                    results.push_back({nums[i],nums[j],nums[k]});
                    //跳过重复的 j 和 k,注意需要循环因为可能不只是一次
                    while(j<k && nums[j]==nums[j+1]) j++;
                    while(j<k && nums[k]==nums[k-1]) k--;
                    j++;
                    k--;
                }
            }
        }
        return results;
    }
};
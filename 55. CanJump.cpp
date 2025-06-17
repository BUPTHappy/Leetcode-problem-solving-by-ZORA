//
// Created by Zhuoer LIU on 2025-06-17.
//
#include <iostream>
using namespace std;

//经典的贪心算法：我们只考虑每一步的最优情况，但需要每一步都比较确保没有0这种极端情况
class Solution{
public:
    bool canJump(vector<int>& nums){
        int maxReach=0;
        for(int i=0; i<nums.size(); ++i){
            if(i>maxReach) return false;
            maxReach = max(maxReach,i+nums[i]);
        }
        return true;
    }
};
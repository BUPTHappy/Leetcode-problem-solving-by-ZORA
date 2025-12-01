//
// Created by Zhuoer LIU on 2025-12-01.
//
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l=0; //l永远指向下一个非零元素应该放的位置

        for(int r=0; r<nums.size(); r++){
            if(nums[r]!=0){
                swap(nums[l],nums[r]);
                l++;
            }
        }
    }
};
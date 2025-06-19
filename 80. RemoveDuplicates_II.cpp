//
// Created by Zhuoer LIU on 2025-06-19.
//
#include<iostream>
using namespace std;

//本题是第26题的变体，可以保留2个相同的，再多的就cut
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()<=2) return nums.size();
        int end =1;
        for(int i=2; i<nums.size(); ++i){
            if(nums[i]!=nums[end-1]){  //这里是关键，你和前一个是否一样我不管，但你和前2个如果一样的话就不能留了
                ++end;
                nums[end]=nums[i];
            }
        }
        return end+1;
    }
};
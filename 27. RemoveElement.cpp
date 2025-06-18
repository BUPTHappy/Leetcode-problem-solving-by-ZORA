//
// Created by Zhuoer LIU on 2025-06-18.
//
#include<iostream>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0;
        for(int i=0; i<nums.size();){
            if(nums[i]==val){
                nums.erase(nums.begin()+i);  //erase里面必须是迭代器
            }else{
                ++i;
                ++k;
            }
        };
        return k;
    }
};
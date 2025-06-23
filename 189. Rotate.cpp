//
// Created by Zhuoer LIU on 2025-06-23.
//
#include <iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //这里是手写了reverse函数，其实也可以直接调用reverse方法
        auto reverse = [&] (int i, int j){
            while(i<j){
                swap(nums[i++],nums[j--]);
            }
        };

        int n=nums.size();
        k %=n; //轮转k次等于轮转k%n次

        //这部分就是对向右轮转k次的解读的核心
        reverse(0, n-1);
        reverse(0,k-1);
        reverse(k,n-1);
    }
};

//
// Created by Zhuoer LIU on 2025-07-09.
//
#include <vector>
using namespace std;

//answer[i] = 左边所有数的乘积 * 右边所有数的乘积
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return {};
        vector<int> ans (len,1);
        ans[0] = 1;
        int temp = 1; // 存储右边乘积

        // 第一步：构建左边乘积（从左往右）
        // ans[i] = nums[0]*...*nums[i-1]
        for(int i = 1; i<len; i++){
            ans[i]=ans[i-1]* nums [i-1];
        }

        // 第二步：构建右边乘积（从右往左），同时乘到 ans 上
        for (int i = len - 2; i >= 0; i--) {
            temp *= nums[i + 1]; // nums[i+1] 是右边第一个元素
            ans[i] *= temp; // ans[i] 原来是左边乘积，这里乘上右边
        }
        return ans;
    }
};
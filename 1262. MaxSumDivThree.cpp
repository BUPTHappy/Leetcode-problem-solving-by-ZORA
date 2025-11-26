//
// Created by Zhuoer LIU on 2025-11-26.
//
#include <vector>
using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        //初始化三个状态：dp[0]表示余数为0的最大和，dp[1]余数为1的，dp[2]余数为2的
        vector<int> dp = {0, INT_MIN, INT_MIN};

        for(int num:nums){
            //创建临时数组保存更新前的状态
            vector<int> temp =dp;
            //对每个可能的余数状态进行转移
            for(int i=0; i<3; i++){
                if(temp[i] != INT_MIN){
                    int new_sum = temp[i]+num;
                    int reminder = new_sum %3;
                    dp[reminder] = max(dp[reminder],new_sum);
                }
            }
        }
        return dp[0];
    }
};
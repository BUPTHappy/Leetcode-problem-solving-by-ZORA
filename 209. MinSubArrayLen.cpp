//
// Created by Zhuoer LIU on 2025-11-29.
//

#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0;
        int sum=0;
        int minLength=INT_MAX;
        for(int r=0; r<nums.size(); r++){
            sum+=nums[r];
            while(sum>=target){ //这里不是if是while，否则它就只会收缩一次
                minLength=min(minLength,r-l+1);
                sum-=nums[l];
                l++;
            }
        }
        return minLength == INT_MAX ? 0 : minLength; //最后这个处理也很关键
    }
};
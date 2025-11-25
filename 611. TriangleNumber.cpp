//
// Created by Zhuoer LIU on 2025-11-25.
//
#include <vector>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count=0;

        for(int k=nums.size()-1; k>=1; k--){ //先找到一个最大边
            int i=0;
            int j=k-1;
            while(i<j){  //这个不能忘，不然双指针在一个k只运行了一次，没动起来
                if(nums[i]+nums[j]>nums[k]){
                    count += j-i; //如果i都满足，说明i到j-1之间的数字都满足这个条件，因为已经排序好
                    j--; //并且这个过了我们可以接着尝试更小一点的j
                }else{
                    i++; //如果这个没过，尝试更大一点的i
                }
            }
        }
        return count;
    }
};
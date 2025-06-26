//
// Created by Zhuoer LIU on 2025-06-26.
//
#include <iostream>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int position = nums.size()-1;
        int steps=0;
        while(position>0){
            for(int i=0; i<nums.size();++i){
                if(i+nums[i]>=position){   //倒着的最优解
                    position = i;  //替换末尾元素，找下一个逆向最优解
                    steps++;
                    break;
                }
            }
        }
        return steps;
    }
};
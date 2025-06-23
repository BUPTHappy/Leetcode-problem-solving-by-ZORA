//
// Created by Zhuoer LIU on 2025-06-23.
//
#include <iostream>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x=0, vote=0;
        for(int num : nums){
            if(vote==0) x=num;
            vote+= num==x ? 1:-1;
        }
        return x;
    }
};
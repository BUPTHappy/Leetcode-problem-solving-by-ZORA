//
// Created by Zhuoer LIU on 2025-12-15.
//
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int eor=0;
        for(int n:nums){
            eor ^= n;
        }
        return eor;
    }
};
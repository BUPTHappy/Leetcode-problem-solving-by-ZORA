//
// Created by Zhuoer LIU on 2025-12-16.
//
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int eor1 = 0;
        for (int n : nums) eor1 ^= n;

        unsigned int rightOne = (unsigned int)eor1 & (-(unsigned int)eor1); //特别注意，这里转换为全程无符号运算
        int eor2 = 0;

        for (int n : nums) {
            if ((n & rightOne) == 0) {
                eor2 ^= n;
            }
        }
        return {eor2, eor1 ^ eor2};
    }
};
//
// Created by Zhuoer LIU on 2025-12-17.
//
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n>0 && 1162261467 % n==0;
    }
};
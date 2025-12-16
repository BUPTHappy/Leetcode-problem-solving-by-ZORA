//
// Created by Zhuoer LIU on 2025-12-17.
//
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && n == (n & -n); //用的就是brain kernighan算法找到最右侧的1
        //一个核心基础就是2的幂的数二进制都只会有一个1
    }
};
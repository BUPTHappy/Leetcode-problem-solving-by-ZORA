//
// Created by Zhuoer LIU on 2025-12-17.
//
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans=x^y;
        int count=0;
        while(ans >0){
            ans &= (ans - 1);  // 每次消除最右边的1
            count++;
        }
        return count;
    }
};
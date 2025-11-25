//
// Created by Zhuoer LIU on 2025-11-25.
//
#include <string>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int count_map[128]={0};
        for (char c:s){
            count_map[c]++;
        }

        int results=0;
        bool hasOdd = false;

        //记住我们关注的就是多长，不是具体组成的长什么样
        for(int c : count_map){
            results+=(c/2)*2;  //相当于只去最小的对数（偶数），因为它们成对可以放到中线的两边
            if(c%2==1){
                hasOdd=true;
            }
        }

        return hasOdd ? results+1: results;  //如果有hasOdd的话，可以最多加一个中心
        //（记住我们求的是最长，所以在满足回文的情况下可以最多再加1个）

    }
};
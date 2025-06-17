//
// Created by Zhuoer LIU on 2025-06-17.
//
#include <iostream>
using namespace std;
#include <string>

class Solution {
public:
    string longestPalindrome(string s) {
        int start=0;
        int maxLen=0;
        for(int i=0;i<s.size();i++){
            centralExpand(s,i,i,start,maxLen);
            centralExpand(s,i,i+1,start,maxLen);
        }
        return s.substr(start,maxLen);
    }

    void centralExpand(string& s, int left, int right, int & start, int & maxLen){
        while(left>=0 && right<s.size() && s[left]==s[right]){
            --left;
            ++right;
        }
        int len=right-left-1;  //因为 while 循环结束时 left 和 right 已经越界或不匹配了，实际合法的是 [left + 1, right - 1]

        //更新最大的长度
        if(len>maxLen){
            maxLen=len;
            start=left+1;
        }
    }
};
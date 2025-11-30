//
// Created by Zhuoer LIU on 2025-11-30.
//
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> charIndex(128,-1); //记录字符最后出现的位置
        int l=0;
        int maxLen=0;
        for(int r=0; r<s.size();r++){
            if(charIndex[s[r]] >=l){  //发现重复字符且在当前的窗口内
                l=charIndex[s[r]]+1;  //跳到重复字符的下一个位置
            }

            charIndex[s[r]]=r;
            maxLen = max(maxLen,r-l+1);
        }
        return maxLen;
    }
};
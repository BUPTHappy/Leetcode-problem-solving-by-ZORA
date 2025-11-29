//
// Created by Zhuoer LIU on 2025-11-29.
//
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> freq(26,0);
        for(char c:p) freq[c-'a']++;
        int count = p.size(); //需要匹配的总字符数量
        int l=0;
        vector<int> results;
        for(int r=0; r<s.size();r++){
            if(freq[s[r]-'a'] >0) count--;
            freq[s[r]-'a']--;

            //这个比较关键，是我没想到怎么收缩的:也就是不让右侧指针一直往右延长，左侧也得收缩的
            //滑动窗口的大小要始终小于p的大小的
            if(r-l+1>p.size()){
                if(freq[s[l]-'a'] >=0) count++;
                freq[s[l]-'a']++;
                l++;
            }

            //检查是否找到了
            if(count == 0 && r-l+1 == p.size()){
                results.push_back(l); //很巧妙的是刚好l也记录了起始指针
            }
        }
        return results;
    }
};
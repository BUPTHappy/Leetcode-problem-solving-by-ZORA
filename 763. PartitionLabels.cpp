//
// Created by Zhuoer LIU on 2025-11-21.
//
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        //先有预处理：记录每个字母最后一次出现的位置
        int last[26]; //一个有 26 个元素的 int 数组
        int length = s.size();
        for (int i=0; i<length; i++){
            last[s[i]-'a']=i;  //这一步很关键我们把每个字母的最后一次出现的位置就记录在了last数组里（s[i]-'a'）是一个巧妙的用ascii码得到不同字母的处理
        }

        vector<int> partition;
        int start =0, end=0;
        for(int i=0; i<length; i++){
            end = max(end, last[s[i]-'a']);
            if (i==end){ //如果我们找到了这个字母的最后一次出现了，就可以划这个片区了
                partition.push_back(end-start+1);
                start = end+1;
            }
        }
        return partition;
    }
};
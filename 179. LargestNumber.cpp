//
// Created by Zhuoer LIU on 2025-11-21.
//
#include <vector>
using namespace std;
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for(int num:nums){
            strs.push_back(to_string(num));
        }
        sort(strs.begin(),strs.end(),[](const string& a, const string& b){   //注意一下这个排序的自定义处理，只有这样才满足题目规定
            return a+b > b+a;
        });

        string largestString="";
        for(string str:strs){
            largestString+=str;
        }
        if(largestString[0]=='0') return "0"; //这里括号里面得用''，因为这是拼接完成后的，我们查到的是一个字符
        return largestString;
    }
};
//
// Created by Zhuoer LIU on 2025-11-21.
//

#include <iostream>
#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution{
public:
    string removeKdigits(string num, int k){
        stack<char> st;
        for(char c:num){
            while(!st.empty() && k>0 && c<st.top()){
                st.pop();
                k--;
            }
            st.push(c);
        }

        //然后处理可能没删完的情况
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }

        //然后要组装结果字符串（从栈里面）
        string results = "";
        while(!st.empty()){
            results += st.top();
            st.pop();
        }
        reverse(results.begin(), results.end());

        //然后处理前导0以及结果直接为0情况
        int start = 0;
        while(start<results.size() && results[start]=='0'){
            start++;
        }

        results = start ==results.size() ? "0" : results.substr(start);

        return results;
    }
};
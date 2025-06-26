//
// Created by Zhuoer LIU on 2025-06-26.
//
#include <iostream>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end(),greater<int>());  //降序排序
        int h=0;
        for(int i=0; i<citations.size(); ++i){
            if(citations[i]>=i+1){  //排序+逆向查找，就本题的关键
                h=i+1;
            }else{
                break;
            }
        }
        return h;
    }
};
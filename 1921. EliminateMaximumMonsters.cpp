//
// Created by Zhuoer LIU on 2025-06-09.
//
#include<iostream>
using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        int count=0;
        vector<int>timeTocity(n); //不用迭代更新距离，而是用时间做判断

        for (int i=0; i<n; i++){
            timeTocity[i]=(dist[i]+speed[i]-1)/speed[i]; //计算 a / b 的向上取整: {a+b-1/b}
        }
        sort(timeTocity.begin(),timeTocity.end());
        for(int i=0; i<n; i++){
            if(timeTocity[i]<=i){
                return i; //这里是需要特别理解的
            }
        }
        return n;
    }
};
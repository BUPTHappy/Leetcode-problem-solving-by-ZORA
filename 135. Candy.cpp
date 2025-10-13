//
// Created by Zhuoer LIU on 2025-10-13.
//
#include<iostream>
#include<function>
using namespace std;

//贪心问题：这里的贪心策略即为，在每次遍历中，只考虑并更新相邻一侧的大小关系
class Solution{
    public:
        int candy(vector<int>& ratings){
            int child_n = ratings.size();
            vector<int> candies(child_n,1);

            //从左到右查一遍
            for (int i=1; i<child_n; i++){  //注意第二个条件
                if(ratings[i]>ratings[i-1]){
                    candies[i] = candies[i-1]+1;
                }
            }
            //再从右到左查一遍
            for (int i=child_n-1; i>0; i--){ //注意第二个条件
                if(ratings[i-1]>ratings[i]){
                    candies[i-1] = max(candies[i-1],candies[i]+1);
                }
            }
            return accumulate(candies.begin(),candies.end(),0);
        }
};
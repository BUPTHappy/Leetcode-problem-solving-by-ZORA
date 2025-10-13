//
// Created by Zhuoer LIU on 2025-10-13.
//
#include<iostream>
using namespace std;

//在样例中，排序后的数组为[[1,2], [1,3], [2,4]]。按照我们的贪心策略，首先初始化为区间
//[1,2]；由于[1,3] 与[1,2] 相交，我们跳过该区间；由于[2,4] 与[1,2] 不相交，我们将其保留。因
//此最终保留的区间为[[1,2], [2,4]]。

class Solution{
    public:
        int eraseOverlapIntervals(vector<vector<int>> & intervals){
            sort(intervals.begin(),intervals.end(),
            [](vector<int>&a, vector<int>&b){return a[1]<b[1];});  //一个lambda函数指导sort怎么排序，这是sort模版函数第三个元素的可选要求（compare的规则）

            int removed = 0, prev_end = intervals[0][1]; //先把第一个元素的结尾保留下来
            for (int i=1; i<intervals.size(); ++i){
                if(intervals[i][0] < prev_end){ //我们采取的贪心策略为，优先保留结尾小且不相交的区间
                   ++removed;
                }else{
                    prev_end = intervals[i][1];
                }
            }
            return removed;
        }
};
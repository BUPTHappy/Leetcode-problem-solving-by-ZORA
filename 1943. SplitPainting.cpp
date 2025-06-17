//
// Created by Zhuoer LIU on 2025-06-10.
//
#include<iostream>
#include<map>
using namespace std;

//差分数组的应用
class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<int, long long> diff;  //由于 map 是自动按 key 排序的，所以我们是按从左到右顺序处理这些位置

        //差分数组记录颜色的变化
        for (const auto& seg :segments){ //遍历每个 segments 中的元素 seg
            int start = seg[0], end = seg[1], color = seg[2]; //将三元组拆成具体变量
            diff[start] += color;
            diff[end] -= color;
        }

        vector<vector<long long>> res;
        long long colorSum=0;
        int prev = -1;

        for(const auto& [pos,delta] : diff){
            if(colorSum>0 && prev!=-1){
                res.push_back({(long long)prev,(long long)pos,colorSum});
            }
            colorSum += delta;
            prev=pos;
        }

        return res;
    }
};
//
// Created by Zhuoer LIU on 2025-10-13.
//
#include <iostream>
using namespace std;


class Solution{
    public:
        int findContentChildren(vector<int>& g, vector<int> &s){
            sort(g.begin(),g.end());
            sort(s.begin(),s.end());

            int child_idx = 0, cookie_idx = 0;
            int children_num = g.size(), cookies_num = s.size(); //size不是-1的，直接是有多少个
            while(child_idx < children_num && cookie_idx < cookies_num){  //所以这里不能写=号
                if(g[child_idx] <= s[cookie_idx]){

                    ++child_idx;
                }

                ++cookie_idx;  //这里无论如何都会要处理下一个饼干了，因为前一个饱不了下一个也不会饱，这个饼干喂不饱人，用下一个

            }

        return child_idx;  //返回最后喂饱了几个小孩
       }
};


//
// Created by Zhuoer LIU on 2025-11-25.
//
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        priority_queue<int, vector<int>, greater<int>> pq; //最小堆，栈顶总是最小的 存储结束时间

        int i=0, count=0;
        for(int day=1; day<=100000; day++){  //按天遍历，从第一天到最大结束日期
            // 处理当天有开始的会议，因为你一天天遍历，所以不会漏掉
            while(i<events.size() && events[i][0]==day){
                pq.push(events[i][1]); //把它的结束日期放到最小堆里
                i++;
            }

            //移除已经过期的会议
            while(!pq.empty() && pq.top()<day){
                pq.pop();
            }

            //参加结束时间最早的会议
            if(!pq.empty()){
                pq.pop(); //这个决定参加了
                count++;  //计数
            }
        }
        return count;
    }
};
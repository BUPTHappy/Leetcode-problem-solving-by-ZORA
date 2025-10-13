//
// Created by Zhuoer LIU on 2025-10-13.
//

#include <iostream>
using namespace std;
class Solution{
    public:
        int minMeetingRooms(vector<vector<int>> & intervals){
            //1.先按照会议开始时间排序
            sort(intervals.begin(), intervals.end());
            //2.创建一个最小堆（就是最小的数永远在堆顶）
            priority_queue<int, vector<int>, greater<int>> pq;  //注意最小堆的写法（最大堆直接是priority_queue<int>）

            for(auto &it : intervals){
                int start = it[0], end = it[1];

                //如果最早开始的会议已经结束
                if(!pq.empty() && start >= pq.top()){
                    pq.pop();
                }
                pq.push(end);
            }
            return pq.size(); //最后需要多少会议室就是遍历
      }
};


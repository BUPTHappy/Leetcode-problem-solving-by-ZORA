//
// Created by Zhuoer LIU on 2025-11-29.
//
#include <vector>
#include <priority_queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n= nums.size();
        priority_queue<pair<int, int>> q; //最大堆，最大的数永远在堆顶
        for(int i=0; i<k ; i++){
            q.emplace(nums[i],i); //这样把当前窗口内的元素和它的下标放进最大堆里
        }

        vector<int> ans = {q.top().first}; //这相当于是第一个窗口里找到的最大值

        //循环从 i = k 开始，每次处理新加入的元素 nums[i] 并更新窗口，其实这里隐藏的左边界是i - k + 1
        for(int i=k; i<n; i++){
            q.emplace(nums[i],i);

            //如果堆顶元素的下标 <= i - k，说明它在窗口左侧之外，需要移除
            while(q.top().second <= i-k){
                q.pop();
            }
            ans.push_back(q.top().first);
        }

        return ans;
    }
};
//
// Created by Zhuoer LIU on 2025-12-13.
//
#include <vector>
#include <priority_queue>
using namespace std;

class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> max_heap; //大根堆，存入double的数据
        double sum = 0;
        for(int n:nums){
            max_heap.push(n);
            sum+=n;
        }

        sum /= 2; //这是目前我们还需要减去的目标
        int ans=0; //这是我们的答案，就是操作了几次
        for(double minus=0, curr; minus<sum; ans++, minus+=curr){
            double temp = max_heap.top();
            max_heap.pop();
            curr =temp/2;
            max_heap.push(curr);
        }
        return ans;
    }
};
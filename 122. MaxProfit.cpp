//
// Created by Zhuoer LIU on 2025-06-24.
//
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int n = prices.size();
        for(int i=1; i<prices.size(); ++i){
            ans += max(0,prices[i]-prices[i-1]);
        }
        return ans;
    }
};
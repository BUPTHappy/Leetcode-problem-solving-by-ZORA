//
// Created by Zhuoer LIU on 2025-12-03.
//
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(const vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;

        if (arr[0] > arr[1]) return 0;
        if (arr[n - 1] > arr[n - 2]) return n - 1;

        int l = 1, r = n - 2, m, ans = -1;

        while (l <= r) {
            m = (l + r) / 2;

            if (arr[m - 1] > arr[m]) {
                r = m - 1; //直接去左侧二分
            } else if (arr[m] < arr[m + 1]) {
                l = m + 1; //直接去右侧二分
            } else {
                ans = m;  //找到峰值点了
                break;
            }
        }
        return ans;
    }
};
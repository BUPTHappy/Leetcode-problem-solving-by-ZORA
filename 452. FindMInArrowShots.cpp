//
// Created by Zhuoer LIU on 2025-11-21.
//
#include <vector>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](vector<int>& a, vector<int>& b){return a[1]<b[1];});
        int prev_end = points[0][1];
        int removed=0;
        for(int i=1; i<points.size(); i++){
            if(points[i][0]<=prev_end){
                removed++;
            }else{
                prev_end = points[i][1];
            }
        }
        int origin_n = points.size();
        return origin_n-removed;
    }
};
//
// Created by Zhuoer LIU on 2025-11-25.
//
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_tank=0;
        int curr_tank=0;
        int starting_station=0;
        for (int i=0; i<gas.size(); i++){
            total_tank += gas[i]-cost[i];
            curr_tank += gas[i]- cost[i];

            //如果当前油量已经是负的了，说明从目前我们尝试的start是无法到达i+1
            //包括start和i中间任何一个点作为起点都不能到
            if(curr_tank <0){
                starting_station = i+1;
                curr_tank=0;
            }
        }

        return total_tank >=0 ? starting_station : -1;

    }
};
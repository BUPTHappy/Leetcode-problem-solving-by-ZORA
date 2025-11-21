//
// Created by Zhuoer LIU on 2025-11-21.
//
#include <iostream>
#include <vector>
#include  <algorithm>
using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int countPlayer = 0; int countTrainer = 0;
        int sizePlayer = players.size(); int sizeTrainer = trainers.size();
        while(countPlayer<sizePlayer && countTrainer<sizeTrainer){
            if (players[countPlayer]<=trainers[countTrainer]){
                ++countPlayer;
            }
            ++countTrainer;
        }
        return countPlayer;
    }
};
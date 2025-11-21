//
// Created by Zhuoer LIU on 2025-11-21.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sizeBed = flowerbed.size();
        int actual_n=0;
        for(int i=0; i<sizeBed; i++){
            if(flowerbed[i]==0){
                if((i==0 || flowerbed[i-1]==0)&&(i==sizeBed-1 ||flowerbed[i+1]==0)){
                    actual_n++;
                    flowerbed[i]=1;
                }
            }
        }
        return actual_n>=n;

    }
};

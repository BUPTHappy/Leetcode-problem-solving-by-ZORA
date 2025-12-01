//
// Created by Zhuoer LIU on 2025-12-01.
//
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int water=0;
        int l=0,r=height.size()-1;
        int leftMax=0, rightMax=0;
        while(l<=r){
            if(leftMax<rightMax){
                if(height[l]>leftMax){
                    leftMax=height[l];
                }else{
                    water+=leftMax-height[l];
                }
                l++;
            }else{
                if(height[r]>rightMax){
                    rightMax=height[r];
                }else{
                    water+=rightMax-height[r];
                }
                r--;
            }
        }

        return water;
    }
};
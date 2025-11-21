//
// Created by Zhuoer LIU on 2025-11-21.
//
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        //这题的核心思路时用双指针：原理是，移动两个边中较短的会带来面积提升的可能性，但移动长的就总不会提升
        int length = height.size();
        int left = 0, right = length-1;
        int maxVal=0;
        while(left<right){
            int squareVal=min(height[left],height[right])*(right-left);
            if(squareVal>maxVal){
                maxVal = squareVal;
            }
            if(height[left]<height[right]){
                left++;
            }else{  //如果不处理相等情况的话，就会导致相等时无法处理而超时
                right--;
            }
        }
        return maxVal;
    }
};
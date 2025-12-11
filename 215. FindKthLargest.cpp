//
// Created by Zhuoer LIU on 2025-12-11.
//
#include <srand>

class Solution {
public:
    int left=0, right=0; //分别记录中间=x的第一个位置和最后一个位置

    int findKthLargest(vector<int>& nums, int k) {
        return quicksort(nums, nums.size()-k);
    }

    int quicksort(vector<int>& nums, int x){
        int ans=0;
        for(int l=0, r=nums.size()-1; l<=r;){
            partition(nums, l,r, nums[l+ rand()%(r-l+1)]);

            if(x<left){
                r = left-1;
            }else if (x>right){
                l = right+1;
            }else{
                ans = nums[x];
                break;
            }
        }
        return ans;
    }

    //荷兰国旗优化的选择排序的分区思路
    void partition(vector<int>& nums, int l, int r, int x){
        left=l;
        right=r;
        int i=l;
        while(i<=right){
            if(nums[i]<x){
                swap(nums[i++], nums[left++]);
            }else if (nums[i]>x){
                swap(nums[i], nums[right--]);
            }else{
                i++;
            }
        }
    }

};
//
// Created by Zhuoer LIU on 2025-12-09.
//
#include <vector>
using namespace std;

static int MAX = 50001;
static vector<int>help(MAX); //一定要注意这里，动态内存空间的坑

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size()>1){
            sort(nums,0,nums.size()-1);
        }
        return nums;
    }

    void sort(vector<int>&nums, int l, int r){
        if(l==r){
            return;
        }
        int m=(r+l)/2;
        sort(nums, l,m);
        sort(nums, m+1,r);
        merge(nums,l,m,r);
    }

    void merge(vector<int>&nums, int l, int m, int r){
        int a=l;
        int i=l;
        int b=m+1;
        while(a<=m && b<=r){
            help[i++] = nums[a]<nums[b] ? nums[a++] : nums[b++];
        }
        while(a<=m){
            help[i++]=nums[a++];
        }
        while(b<=r){
            help[i++]=nums[b++];
        }
        for(int i=l; i<=r; i++){ //注意复制的时候索引要对上，不能写int i=0
            nums[i]=help[i];
        }
    }
};
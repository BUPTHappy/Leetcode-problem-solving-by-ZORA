//
// Created by Zhuoer LIU on 2025-12-10.
//
#include <vector>
using namespace std;

static int MAX = 50001;
static vector<int> help(MAX);

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return count(nums, 0, nums.size()-1);
    }

    int count(vector<int>& nums, int l, int r){
        if(l==r){
            return 0;
        }
        int m = (r+l)/2;
        return count(nums,l,m) + count(nums,m+1,r) + merge(nums,l,m,r);
    }

    int merge(vector<int>& nums, int l, int m,int r){
        //1. 先求跨左右（现在nums的左右已经有序，是上次最后排好的）
        int count=0;
        for(int i = l,j = m+1; i<=m; i++){
            while(j<=r && (long)nums[i]>(long)nums[j]*2){
                j++;
            }
            count+=j-m-1;
        }

        //2. 要为下次做准备给nums排一下序
        int a = l;
        int b = m+1;
        int k = l;
        while(a<=m && b<=r){
            help[k++] = nums[a]<nums[b]?nums[a++]:nums[b++];
        }
        while(a<=m){
            help[k++]=nums[a++];
        }
        while(b<=r){
            help[k++]=nums[b++];
        }
        for(int i =l; i<=r; i++){
            nums[i]=help[i];
        }

        return count;
    }
};
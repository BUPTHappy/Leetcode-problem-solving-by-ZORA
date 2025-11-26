//
// Created by Zhuoer LIU on 2025-11-26.
//
#include <vector>
using namespace std;


class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        if(p==0) return 0;
        sort(nums.begin(), nums.end());

        //我们维护一个范围 [left, right]，表示答案可能的区间
        //left = 0（最小可能差值）
        //right = nums.back() - nums.front()（最大可能差值）
        int left =0, right= nums.back()-nums.front();

        while(left<right){
            int mid=(left+right)/2;
            int count=0;

            //贪心检查能否找到至少p对差值<=mid的数对
            for(int i=1; i<nums.size();i++){
                if(nums[i]-nums[i-1] <=mid){ //最小差值只会出现在相邻
                    count++;
                    i++; //跳过下一个元素（每个元素只能用一次）
                }
            }
            if(count >= p){
                right=mid;
            }else{
                left = mid+1;
            }
        }

        return left;  //因为当 left == right 时，这个值就是满足条件的最小可能值！
    }
};
//
// Created by Zhuoer LIU on 2025-12-16.
//
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int m=3;
    vector<int> cnt(32);
    for(int n:nums){
        for(int i=0; i<32; i++){
            cnt[i] += (n>>i) & 1; //这里是把这个数字这一位的数右移动到最低位和1做&运算，就是看它是不是1
            //这样统计出来每一位1的个数（如果满足是m次的话应该%m是0）
        }
    }

    int ans=0;
    for(int i=0; i<32; i++){
        if(cnt[i]%m != 0){ //把那么就是这个数了，把这个数拼出来
            ans |= 1<<i; //把这一个找出来次数不对的1，左移位到对应的位置，然后用或运算或到答案里
        }
    }
    return ans;
}
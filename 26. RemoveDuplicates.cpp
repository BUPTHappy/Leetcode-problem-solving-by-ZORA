//
// Created by Zhuoer LIU on 2025-06-19.
//
#include <iostream>
using namespace std;
//我的答案：但是复杂度高，因为我用了erase方法这个方法需要删除的时候把后面的每一个元素都往前挪动
class Solution1 {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i=1; i<nums.size();++i){
            if(nums[i]==nums[i-1]){
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        return nums.size();
    }
};

//官方答案：【双指针】
class Solution2 {
public:
int removeDuplicates(vector<int>& nums) {
    int end=0 ; //slow为数列最后的一个元素
    if(nums.size()==0) return 0;
    for(int i=1; i<nums.size();++i){ //下一个和目前的检查到的最后一个做比较
        if(nums[i]!=nums[end]){
            ++end;  //这里是关键，因为是前+，所以判断的两个和最后替换的是不同的
            nums[end]=nums[i]; //不相等就可以放入最终的数组，这里放入的方式是替换
        }
    }
    return end+1;
}
};
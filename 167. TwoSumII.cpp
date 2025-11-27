//
// Created by Zhuoer LIU on 2025-11-27.
//

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0, right=numbers.size()-1;
        vector<int> result;

        while(left<right){
            int curr_sum=numbers[left]+numbers[right];
            if(curr_sum<target){
                left++;
                continue;
            }else if(curr_sum>target){
                right--;
                continue;
            }else{
                result.push_back(left+1);
                result.push_back(right+1);
                break;
            }
        }
        return result;
    }
};
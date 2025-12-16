//
// Created by Zhuoer LIU on 2025-12-17.
//

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(left<right){
            right -=(right & -right);
        }
        return right;
    }
};
//
// Created by Zhuoer LIU on 2025-11-25.
//

#include <string>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int left =0, right=s.size()-1;

        while(left<right){
            if(s[left]==s[right]){
                left++;
                right--;
            }else{
                return isPalindrome(s, left, right-1) || isPalindrome(s, left+1, right); //主函数中遇到不匹配时调用两次辅助函数
            }
        }
        return true;
    }

    //一个辅助函数，用于判断一个序列是否为回文序列Palindrome
    bool isPalindrome(const string& s, int left, int right){
        for(int i=left, j=right; i<j; i++, j--){
            if(s[i]!=s[j]){
                return false;
            }
        }
        return true;
    }
};
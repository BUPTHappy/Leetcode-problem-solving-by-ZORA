//
// Created by Zhuoer LIU on 2025-11-26.
//
#include <string>
using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string num = to_string(n);
        for (int i=num.size()-1; i>0; i--){
            if(num[i-1]>num[i]){
                num[i-1]--;
                for (int j=i;j<num.size();j++) num[j]='9';
            }
        }
        return stoi(num);

    }
};
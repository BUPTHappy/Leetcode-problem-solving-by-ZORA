//
// Created by Zhuoer LIU on 2025-12-18.
//
#include <limit.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == INT_MIN){
            return 1;
        }else if(dividend != INT_MIN && divisor != INT_MIN){
            return division(dividend,divisor);
        }else if(divisor == INT_MIN){
            return 0;
        }else if (dividend == INT_MIN && divisor==-1){
            return INT_MAX;
        }else{
            dividend = add(dividend , divisor>0 ? divisor : neg(divisor));
            int ans = division(dividend,divisor);
            ans = add(ans, divisor>0 ? neg(1):1);
            return ans;
        }
    }

    int add (int a, int b){
        int ans = 0;
        while(b!=0){
            ans = a^b;
            b = (a&b)<<1;
            a = ans;
        }
        return ans;
    }

    int neg(int n){
        return add((~n),1);
    }

    int division(int a, int b){
        int x = a < 0 ? neg(a) : a;
        int y = b < 0 ? neg(b) : b;
        int ans=0;

        for(int i=30; i>=0; i--){
            if((x>>i) >= y){
                ans |= (1<<i);
                x = add(x, neg(y<<i));
            }
        }

        return a<0 ^ b<0 ? neg(ans) : ans;
    }
};
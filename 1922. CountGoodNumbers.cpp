#include<iostream>
using namespace std;

class Solution{
    int const MOD=1e9+7;

    //快速幂代码实现（循环版）
    /*在 C++ 中，没有内置整数幂运算符，所以必须手写,^是按位异或*/
    long long power(long long base,long long exp){
        long long res=1;
        while(exp>0){
            if(exp%2==1){
                res=res*base%MOD;
            }
            base=base*base%MOD;
            exp/=2;
        }
        return res;
    }

public: int countGoodNumbers(long long n){
//正着按照每一位的可能性推理，result = (5 ^ ((n + 1)/2)) × (4 ^ (n / 2)) % MOD
         long long evenCount=(n+1)/2;
         long long oddCount=n/2;
         return ((power(5,evenCount)*power(4,oddCount))%MOD);
    }
};
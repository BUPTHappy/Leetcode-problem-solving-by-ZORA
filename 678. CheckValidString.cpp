//
// Created by Zhuoer LIU on 2025-11-26.
//
#include <string>
using namespace std;

class Solution{
public:
    bool checkValidString(string s){
        int min_open=0, max_open=0;
        for(char c:s){
            if(c =='(') {
                min_open++;
                max_open++;
            }else if(c==')'){
                min_open--;
                max_open--;
            }else{
                min_open--;
                max_open++;
            }

            if(max_open<0) return false;  //导致这种情况的只可能是右括号太多
            min_open = max(min_open,0); //左括号不能是负的
        }
        return min_open ==0; //min是最好的情况下，就是我不用*给左括号雪上加霜的情况下你还合不上就是不行了
    }
    }
};
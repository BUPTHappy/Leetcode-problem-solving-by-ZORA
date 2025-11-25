//
// Created by Zhuoer LIU on 2025-11-25.
//
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> gate(26), num(26);
        //【基操】先记录一下每个字母都在里面出现了几次
        for(char c : s){
            num[c-'a']++;
        }

        string results;
        for(char c:s){
            if(!gate[c-'a']){  //该字母还没有存入过
                while(!results.empty() && results.back() > c){
                    if(num[results.back()-'a']>0){ //如果这个栈顶字母我们之后还有，还得处理
                        gate[results.back()-'a']=0;  //要移除了，就把flag恢复，下次还可以处理这个字母
                        results.pop_back();
                    }else{
                        break;
                    }
                }
                results.push_back(c); //如果刚刚那个back的字符后面都没有了，它就出现一次，所以你不能动它，就算比他小你也直接放后面就好了
                gate[c-'a']=1;  //存进去了，就把flag标上
            }
            num[c-'a']-=1;  //就算这个字符因为已经里面有了没做什么处理，但它也算是遍历过了，就在记录本里更新一下，因为这个本会用于判断未来还有没有
        }
        return results;
    }
};
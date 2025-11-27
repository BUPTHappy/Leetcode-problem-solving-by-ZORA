//
// Created by Zhuoer LIU on 2025-11-27.
//
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<bool> valid(128,false); //记录t串中有哪些字符
        vector<int>freq(128,0); //记录t串的字符在s中对应缺失多少还没匹配

        //先对t的字符串做个统计
        for(int i=0; i<t.length();i++){
            valid[t[i]]=true;
            freq[t[i]]++;
        }

        int count=0;
        int min_l = -1, min_length=-1;
        for(int l=0, r=0; r<s.length();r++){
            if(!valid[s[r]]){
                continue;
            }
            if(--freq[s[r]] >= 0){ //它这样应该是说明s[r]匹配上了,这里一定注意先--再判断
                count++; //记录目前有多少已经匹配上了
            }

            //都匹配完了但可能不一定是最短的
            while(count == t.length()){
                if(min_length==-1 || r-l+1 < min_length){
                    //不论如何都把现在的最小值记一下
                    min_l=l;
                    min_length=r-l+1;
                }

                //然后我们要动l了，所以把l位置的字符从匹配统计表和变量都移除
                //当然前提是s[l]在t中有
                if(valid[s[l]] && ++freq[s[l]] > 0 ){ //这里也是先++再判断
                    count--;
                }

                l++; //移动l去寻找更短的
            }
        }
        return min_length==-1 ? "" : s.substr(min_l,min_length);
    }
};
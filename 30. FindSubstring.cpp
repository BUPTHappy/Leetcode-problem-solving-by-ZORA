//
// Created by Zhuoer LIU on 2025-11-29.
//
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> word_count;
        for(string str:words){
            word_count[str]++; //直接默认以work为key
        }
        int len = words[0].size();
        int n=words.size();
        vector<int> results;

        //用offset是可以处理所有可能在一个len中的相对偏移
        for(int offset=0; offset<len;offset++){
            unordered_map<string, int> window;
            int l=offset;

            // 以 len 为步长滑动窗口
            for(int r=offset; r<=(int)s.size()-len; r+=len){
                string currWord=s.substr(r,len);

                //如果没找到
                if(word_count.find(currWord)==word_count.end()){
                    window.clear(); //重置窗口
                    l=r+len;
                    continue;
                }

                window[currWord]++;

                // 收缩窗口直到当前单词不超量(所以这里有个循环逻辑在里面)
                while(window[currWord]>word_count[currWord]){
                    string leftWord = s.substr(l,len);
                    window[leftWord]--;
                    if(window[leftWord]==0) window.erase(leftWord);
                    l+=len;
                }

                //检查是否找到有效窗口
                if((r-l)/len+1 ==n){
                    results.push_back(l);
                }
            }
        }
        return results;
    }
};
//
// Created by Zhuoer LIU on 2025-11-29.
//
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char,int> map;
        if(k==0) return 0;
        int n=s.size();
        int ans=0;

        for(int l=0,r=0; r<n; r++){
            map[s[r]]++;
            while(map.size()>k){
                map[s[l]]--;
                if(map[s[l]]==0){
                    map.erase(s[l]);
                }
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
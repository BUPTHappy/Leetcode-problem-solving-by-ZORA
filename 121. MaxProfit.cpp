//
// Created by Zhuoer LIU on 2025-06-24.
//
#include <isostream>
using namespace std;

class Solution{
public:
	int maxProfit(vector<int>& prices){
		int min = INT_MAX;
		int maxProfit = 0;
		for (int price : prices){
			if(price<min){
				min = price;
			}else{
				maxProfit = max(maxProfit, price-min);
			}
		}
		return maxProfit;
	}
};
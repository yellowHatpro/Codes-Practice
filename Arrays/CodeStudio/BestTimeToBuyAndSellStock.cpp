#include <bits/stdc++.h>
using namespace std;
int maximumProfit(vector<int> &prices){
    int mini= prices[0];
    int maxi= 0;
    for (int i = 1; i < prices.size(); ++i)
    {	if (prices[i]<mini){
    	mini = prices[i];
    	continue;
    }
    	if (prices[i]-mini>=0){
    		maxi = max(maxi,prices[i]-mini);
    	}
    }
    return maxi;
}
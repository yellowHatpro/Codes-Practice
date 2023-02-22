#include <bits/stdc++.h>
using namespace std;
int main(){

}
class BruteSolution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        for(int i =0;i<prices.size();i++){
            for(int j = i ;j< prices.size();j++){
                if(prices[j]>prices[i]){
                    int profit = prices[j]-prices[i];
                    if(profit>max_profit){
                        max_profit = profit;
                    }
                }
            }
        }
        return max_profit;
    }
};
//Time O(n) Space O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_value=prices[0];
        int max_profit=0;
        for(int i=0; i<prices.size();i++){
            if(prices[i]<min_value){
                min_value = prices[i];
            }
            if (prices[i]-min_value>max_profit){
                max_profit = prices[i] - min_value;
            }   
        }
        return max_profit;
        
    }
};

//More readable
class SolutionKadane {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int currMin = prices[0];
        for(int i = 1; i<prices.size(); i++){
            currMin = min(currMin, prices[i]);
            maxProfit = max(maxProfit, prices[i]-currMin);
        }
        return maxProfit;
    }
};
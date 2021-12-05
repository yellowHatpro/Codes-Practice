#include <bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0){
            return 0;
        }
        vector<int>dp(prices.size(),0);
        vector<int> temp = prices;
        temp.pop_back();
        int max = maxProfit(temp);
        dp.push_back(0);
        

    }
};
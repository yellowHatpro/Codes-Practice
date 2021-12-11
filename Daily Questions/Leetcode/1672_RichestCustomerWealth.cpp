#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n = accounts.size();
        int max=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j =0;j<accounts[i].size();j++){
                 cnt+=accounts[i][j];
                 if(cnt>max){
                     max = cnt;
                 }
            }
               cnt=0;
        }
        return max;
    }
};
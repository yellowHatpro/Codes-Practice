#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> juggling(vector<vector<int>> &arr,int n) {
        int maxi = 0;
        int abc = 0;
        int currBall = 0;
        for (int i =  1; i<=3; i++){
        	currBall = i;
        	int ans = 0;
        	for (int j = 0; j < n; ++j)
        	{
        		if (currBall== arr[j][0]){
        			currBall = arr[j][1];
        		} else if (currBall == arr[j][1]){
        			currBall = arr[j][0];
        		}
        		if (currBall==arr[j][2]){
        			ans++;
        		}
        	}
        	if (ans>maxi){
        		maxi = ans;
        		abc = i;
        	}
        }
        vector<int> res = {abc, maxi};
        return res;
    }
};

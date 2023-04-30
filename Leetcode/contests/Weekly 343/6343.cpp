#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	map<pair<int,int>,int> mp;
	int f(int x, int y, int i, int j, int cost, vector<vector<int>>& specialRoads, vector<vector<vector<int>>>& dp){
		if (i<0 || j<0 || i>=x || j>=y){
			return 0;
		}
		if (dp[i][j][cost]!=-1) return dp[i][j][cost];
		int a = f(x,y,i+1,j,abs(x-(i+1))+abs(y-j), specialRoads, dp);
		int b = f(x,y,i,j+1,abs(x-(i)) + abs(y-(j+1)), specialRoads, dp);
		int c = f(x,y,i-1,j,abs(x-(i-1))+abs(y-j), specialRoads, dp);
		int d = f(x,y,i,j-1,abs(x-(i)) + abs(y-(j-1)), specialRoads, dp);
		int x = INT_MAX;
		if (i==spea)
	}

    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        vector<vector<vector<int>>> dp(1e5, vector<vector<int>>(1e5, vector<int>(200,-1)));
        int i = start[0];
        int j = start[1];
        int x = target[0];
        int y = target[1]; 
        return f(x,y,i,j,0, specialRoads, dp);
    }
};
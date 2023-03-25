#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

	void dfs(int node, vector<vector<int>> &rooms, int& n, vector<int>&vis){
		vis[node]=1;
		for (auto edge: rooms[node]){
			if (!vis[edge]) {
				n--;
				dfs(edge,rooms,n,vis);}
		}
	}

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
    	int n = rooms.size()-1;
    	vector<int> vis(n+1);
    	dfs(0,rooms,n,vis);
    	return n==0;
    }
};
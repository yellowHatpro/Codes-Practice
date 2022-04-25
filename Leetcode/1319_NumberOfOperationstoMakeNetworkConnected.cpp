#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(unordered_map<int,vector<int>>& adj, int curr, vector<bool>& visited){
        visited[curr] = 1;
        for(auto i: adj[curr]){
            if(visited[i] == 0)
                dfs(adj, i, visited);
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
    vector<bool> visited(n, false);
    unordered_map<int, vector<int>> adj;
    //STEP 1: Adjacency list
    int edges = 0;
        for (int i = 0; i < connections.size(); ++i) {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
            edges++;
        }
        //STEP 2: DFS
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(adj,i, visited);
                count++;
            }
        }
        if (edges <n-1){
            return -1;
        }
        int redundant = edges - ((n-1)-(count-1));
        if (redundant>=count-1) return count-1;
        return -1;
    }
};
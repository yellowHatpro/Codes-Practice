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

class SolutionEasier {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjList(n+1,vector<int>());
        vector<int> vis(n+1);
        int totalConnectedComp = 0;
        int edges = 0;
        for(auto connection: connections){
            adjList[connection[0]].push_back(connection[1]);
            adjList[connection[1]].push_back(connection[0]);
            edges++;
        }
        if (edges<n-1) return -1;
        for(int i = 0; i<n; i++){
            if (!vis[i]){
                dfs(i,adjList,vis);
                totalConnectedComp++;
            }
        }
        return totalConnectedComp-1;
    }
    private:
        void dfs(int currentNode, vector<vector<int>> & adjList, vector<int>& vis){
            vis[currentNode] = 1;
            for (auto node: adjList[currentNode]){
                if (!vis[node]) dfs(node,adjList, vis);
            }
        }
};
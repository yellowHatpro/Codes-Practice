#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkBipartite(vector<vector<int>> &graph, vector<int>&colored, int currentNode){
        if (colored[currentNode]==-1) colored[currentNode] = 1;
        for (auto itr : graph[currentNode]){
            
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> colored(V,-1);//not colored in beginning
        for (int i = 0; i < V; i++)
        {
            if (!checkBipartite(graph,colored,i)) return false;
        }
        return true;
        
    }
};
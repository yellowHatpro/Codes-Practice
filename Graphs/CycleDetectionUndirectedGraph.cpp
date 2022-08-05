#include <bits/stdc++.h>
using namespace std;

class CycleDetection{
public:
    //V is total nodes
    bool isCycle(int V, vector<vector<int>> adj){
        vector<int> visited(V+1, 0);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (checkForCycle(i, adj, visited, -1)) return true;
            }
                
        }
        return false;
        
    }
private:
    bool checkForCycle(int V, vector<vector<int>> adj, vector<int> &visited, int parent){
        visited[V] = true;
        for(auto itr: adj[V]){
            if (!visited[itr]){
              if (checkForCycle(itr,adj,visited,V)) return true;
            } else if (parent!=itr){
                return true;
            }
        }
        return false;
    }
};
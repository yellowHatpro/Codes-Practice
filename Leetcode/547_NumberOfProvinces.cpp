#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited(isConnected.size(),0);
        int ans = 0;
        for (int i = 0; i < isConnected.size(); i++)
        {
            if(!visited[i]){
                queue<int> pendingCities;
                pendingCities.push(i);
                visited[i] = 1;
                ans+=1;
                while(!pendingCities.empty())
                {
                    int currentNode = pendingCities.front();
                    pendingCities.pop();   
                    for (int j = 0; j<isConnected[currentNode].size();j++){
                        if (!visited[j] && isConnected[currentNode][j]){
                        pendingCities.push(j);
                        visited[j]=1;
                    }
                    }
                }
                
            }
        }
        return ans;
    }
};

class Solution2 {
public:

    void dfs(int node, vector<vector<int>> &adjList, vector<int>& vis ){
        vis[node] = 1;
        for(auto curr: adjList[node]){
            if (!vis[curr]){
                dfs(curr, adjList, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjList(n+1);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i==j) continue;
                if (isConnected[i][j]) adjList[i].push_back(j);
            }
        }
        vector<int> vis(n,0);
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!vis[i]){
                cnt++;
                dfs(i,adjList, vis);
            }
        }
        return cnt;
    }
};
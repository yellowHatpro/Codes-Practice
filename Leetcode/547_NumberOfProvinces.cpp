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
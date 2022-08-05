#include <bits/stdc++.h>
using namespace std;
int totalConnectedComp(vector<vector<int>>&arr, int n, int m) {
	    vector<int> visited(n,0);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if(!visited[i]){
                queue<int> pendingComputers;
                pendingComputers.push(i);
                visited[i] = 1;
                cnt++;
                while (!pendingComputers.empty())
                {
                    int currentComputer = pendingComputers.front();
                    pendingComputers.pop();
                    

                }
                
            }
        }
        
}
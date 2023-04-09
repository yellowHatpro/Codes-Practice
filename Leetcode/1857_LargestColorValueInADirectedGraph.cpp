#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
    	int n = colors.size();
        int ans = 0;
    	vector<vector<int>> res(n,vector<int>(26));
    	vector<vector<int>> adjList(n);
    	vector<int> inDegree(n);
    	for (int i = 0; i < edges.size();i++){
    		adjList[edges[i][0]].push_back(edges[i][1]);
    		inDegree[edges[i][1]]++;
    	}
        queue<int> q;
    	for (int i = 0; i < n ;i++){
            if (inDegree[i]==0) q.push(i);
        }
        int cnt = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans = max(ans, ++res[curr][colors[curr]-'a']);
            cnt++;
            for(auto itr: adjList[curr]){
                for (int i = 0; i < 26; ++i)
                {
                    res[itr][i] = max(res[itr][i], res[curr][i]);
                }
                if (--inDegree[itr]==0){
                    q.push(itr);
                }
            }
        }
        if (cnt < n) return -1;
        return ans;
    }
};
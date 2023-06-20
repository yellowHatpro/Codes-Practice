#include <bits/stdc++.h>
using namespace std;
//Kahn Algorithm
class Solution
{
	public:
	vector<int> topoSort(int n, vector<int> adjList[]) {
	   	vector<int> inDegree(n);
		vector<int> res;
		for (int i = 0; i < n; ++i){
			for(auto node: adjList[i]){
				inDegree[node]++;
			}
		}
		queue<int> q;
		for (int i = 0; i< n; i++){
			if (inDegree[i]==0) q.push(i);
		}
		while(!q.empty()){
			int curr = q.front();
			q.pop();
			res.push_back(curr);
			for(auto itr: adjList[curr]){
				if (--inDegree[itr]==0){
					q.push(itr);
				}
			}
		}
		return res;
	}
};
#include <bits/stdc++.h>
#include <queue>
using namespace std;
//Insert a node in the pq, and from it, insert its neighbours, and out of those choose the one with lesser weight. 
//Greedy algo : Total TC = ElogE + ElogE 
//SC = O(E)
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //min heap
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
      vector<int> vis(V);
      pq.push({0,0});
      int sum = 0;
      //while loop -> E times
      while (!pq.empty()) {
        //pq.top() takes log(PQ SIZE) = log(E)
        auto itr = pq.top();
        pq.pop();
        int node = itr.second;
        int wt = itr.first;
        if (!vis[node]){
          vis[node] = 1;
          sum+=wt;
          // E edges * pq.push = E logE
          for (auto neighbourPair  : adj[node]) {
            int neighbour = neighbourPair[0];
            int edgeWt = neighbourPair[1];
            if (!vis[neighbour]){
              pq.push({edgeWt,neighbour});
            }
          }
        }
      }
      return sum;
    }
};


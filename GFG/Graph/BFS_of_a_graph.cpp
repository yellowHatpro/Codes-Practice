//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:

 void bfs(vector<int>& res, vector<int>& vis, int V, int i, vector<int> adj[]){
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            res.push_back(curr);
            for (auto j: adj[curr])
            {
                if (!vis[j]){
                    q.push(j);
                    vis[j] = 1;
                }
            }
        }
    }
    
        vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> res;
        vector<int> vis(V);
         bfs(res,vis,V,0, adj);
        return res;

    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
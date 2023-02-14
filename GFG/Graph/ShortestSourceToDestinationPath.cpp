//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:

    void bfs(vector<vector<int>>& vis, int& ans, vector<vector<int>> A, int n, int m, int x, int y){
        queue<pair<pair<int,int>, int>> q;
        q.push({{0,0},0});
        vis[0][0] = 1;
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int curDis = q.front().second;
            q.pop();
            for (int row = -1; row <=1; ++row)
            {
                int nrow = i+row;
                int ncol = j;
                if (nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && A[nrow][ncol]==1 ){
                    q.push({{nrow,ncol},curDis+1});
                    vis[nrow][ncol] = 1;
                }
            }
            for (int col = -1; col <=1; ++col)
            {
                int nrow = i;
                int ncol = j+col;
                if (nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && A[nrow][ncol]==1 ){
                    q.push({{nrow,ncol},curDis+1});
                    vis[nrow][ncol] = 1;
                }
            }
            if (i==x && j==y){
                ans = curDis;
            }
        }
    }

    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        vector<vector<int>>vis(N, vector<int>(M,0));
        int ans = -1;
        if (A[0][0]==0) return -1;
        bfs(vis,ans,A,N,M,X,Y);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends
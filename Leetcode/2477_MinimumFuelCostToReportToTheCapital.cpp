#include <bits/stdc++.h>
using namespace std;
class SolutionBFS {
public:
    void countChild(int index, vector<vector<int>> &graph, vector<int> &child)
    {
        child[index]=1;

        for(auto &x: graph[index])
        {
            if(child[x]==0)
            {
                countChild(x,graph,child);
                child[index]+=child[x];
            }
        }

        return;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size()+1;

        vector<vector<int>> graph(n);

        for(int i=0;i<n-1;i++)
        {
            graph[roads[i][0]].push_back(roads[i][1]);
            graph[roads[i][1]].push_back(roads[i][0]);
        }

        vector<int> child(n,0),vis(n,0);

        countChild(0,graph,child);

        queue<int> q;
        q.push(0);
        vis[0]=1;

        long long minFuel = 0;

        while(!q.empty())
        {
            int curr = q.front();
            q.pop();

            for(auto &x: graph[curr])
            {
                if(vis[x]==1)
                    continue;
                int cnt = child[x];
                minFuel+=cnt/seats;

                if(cnt%seats)
                    minFuel++;

                q.push(x);
                vis[x]=1;
            }
        }

        return minFuel;
    }
};
class SolutionDFS{
public:
    long long ans;
    void dfs(vector<int>& vis, vector<vector<int>>& graph, vector<vector<int>> & roads, int seat, int i, vector<int>& r){
        vis[i] = 1;
        for(auto ch : graph[i]){
            if (!vis[ch]){
               dfs(vis, graph, roads, seat, ch, r);
                r[i]+=r[ch];
                ans+= ceil(r[ch]/(double)seat);
            }
        }
        r[i]++;
        return;
    }

   long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        vector<vector<int>> graph(n+1);
        for (int i = 0; i < roads.size(); ++i)
        {
            graph[roads[i][0]].push_back(roads[i][1]);
            graph[roads[i][1]].push_back(roads[i][0]);
        }
        vector<int> child(n+1,0);
        vector<int> vis(n+1,0);
        dfs(vis, graph, roads, seats,0, child);
        return ans;
    }
};
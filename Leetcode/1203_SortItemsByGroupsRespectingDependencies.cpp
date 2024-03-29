#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    //adj can be vector<vector<int>> or vector<unordered_set<int>>
    vector<int> topo_sort(auto& adj, vector<int>& deg, int sz){
        //Kahn's algorithm
        queue<int> q;
        for (int i=0; i<sz; i++)
            if (deg[i]==0) q.push(i);
        vector<int> res;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            res.push_back(x);
            for(int y: adj[x]){
                deg[y]--;
                if(deg[y]==0) q.push(y);
            }
        }
        for(int i=0; i<sz; i++)
            if(deg[i]>0) return {};
        return res;
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // isolated item is a group by itself
        for(int i=0; i<n; i++){
            if (group[i]==-1) group[i]=m++;
        }
        vector<vector<int>> adj_item(n);
        vector<int> deg_group(m, 0), deg_item(n, 0);
        vector<unordered_set<int>> adj_group_set(m);//avoid of multiple edges
        for(int i=0; i<n; i++){
            int to_i=group[i];
            for(int from: beforeItems[i]){
                int from_j=group[from];
                //avoid of multiple edges thx to @karandh83 @Nameresu
                // pointing out the possiblity for multiple edges
                if(to_i!=from_j && adj_group_set[from_j].count(to_i)==0){
                    adj_group_set[from_j].insert(to_i);
                    deg_group[to_i]++;
                }
                adj_item[from].push_back(i);
                deg_item[i]++;
            }
        }
        
        vector<int> sort_group=topo_sort(adj_group_set, deg_group, m);
        vector<int> sort_item=topo_sort(adj_item, deg_item, n); 
    //    print("adj_group",  adj_group);
    //    print("adj_item",  adj_item);
        if (sort_group.empty() || sort_item.empty()) return {};

        vector<vector<int>> item_gp(m);
        for(int i: sort_item)
            item_gp[group[i]].push_back(i);
        
        vector<int> ans;
        for(int i : sort_group) {
            for(int item : item_gp[i]) {
                ans.push_back(item);
            }
        }
        
        return ans;

    }
};

/* Q. You are given a graph with N nodes and M edges. Each edge can be of either red color or blue color.
Given a source and a destination , find the shortest path on this graph such that the path is shortest and the path starts with a red edge and end with a blue edge .
You can switch the color only once ,i.e. , there will be only one vertex after which all the blue edges will be picked in optimal fashion.
Lecture URL : https://unacademy.com/class/graph-series-problem-solving-with-bfs-1/VHHUX7GK
*/
#include <bits/stdc++.h>

using namespace std;
//n -> no of vertices
vector<vector<pair<long long int,long long int>>> adj;//adj matrix


vector<long long int> bfs(int src , int clr, int n){
queue<int> q;
//shortest path k liye distance vector is needed
vector<long long int> dist(n+1,-1);
q.push(src);
dist[src] = 0;
while(!q.empty()){
int i = q.front();
q.pop();
for(auto neighbour : adj[i]){
    if(dist[neighbour.first]!=-1 || neighbour.second!=clr){
        continue;
    }
    q.push(neighbour.first);
    dist[neighbour.first] = dist[i]+1;//graph is unweighted
}
}
return dist;
}

int main(){
    int n , m ;
    cin >> n >> m;
    adj.reserve(n+1);
    while (m--)
    {
        int i , j , c;
        cin>>i>>j>>c;
        adj[i].push_back({j,c});
        adj[j].push_back({i,c});
 
    }

    int src ,dest ;
    cin>>src>>dest;
    vector<long long int> ds = bfs(src,0,n);
    vector<long long int> dd = bfs(dest,1,n);
    long long ans = INT_MAX;

    for(int i=0;i<=n;i++){
        if(i==src || i==dest || ds[i]==-1 || dd[i]==-1){
            continue;
        }
        ans = min(ans,ds[i]+dd[i]); 
    }
    if(ans==INT_MAX){
        ans=-1;
      
    }
      cout<<ans<<endl;
}

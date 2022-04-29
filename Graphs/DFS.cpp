//
// Created by ashu on 29-04-2022.
//

#include <bits/stdc++.h>
using namespace std;

class Graph{
public:
    map<int, bool> visited;
    map<int, vector<int>> adjList;
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }
    void DFS(int u) {
        visited[u] = true;
        cout << u << " ";
        for (auto v: adjList[u]) {
            if (!visited[v]) {
                DFS(v);
            }
        }
    }
};

int main(){
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.DFS(2);
    return 0;
}
#include <iostream>
#include <queue>
using namespace std;   
//DFS traversal of the graph
void printDFS(int** edges , int n, int sv , bool* visited){
    cout<<sv<<" ";
    visited[sv] = true;
    for(int i=0;i<n;i++){
        if(edges[sv][i]==1){
            if(visited[i]){
                continue;}
            printDFS(edges,n,i,visited);
        }
    }
}
void printBFS(int** edges , int n , int sv){
    //for bfs no recursion , we'll use queue
  queue<int> pendingVertices;
  bool* visited = new bool[n];
    for(int i = 0 ; i < n ; i++){
        visited[i] = false;
    }
    pendingVertices.push(sv);
    visited[sv] = true;
    while(!pendingVertices.empty()){
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        cout<<currentVertex<<" ";
        for(int i=0;i<n;i++){
            if(edges[currentVertex][i] == 1 && !visited[i]){
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
delete [] visited;
cout<<endl;
}


int main()
{
    int n;
    int e;
    cin >> n >> e;
    int** edges = new int*[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;//0 means no edge
        }
        
    }
    for (int i = 0; i < e; i++)
    {
        int f,s;
        cin>>f>>s;
        edges[f][s] = 1;//first to second edge
        edges[s][f] = 1;//second to first edge
    }
    bool *visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    cout<<"DFS"<<endl;
    printDFS(edges,n,0,visited);

    cout<<"\nBFS"<<endl;
    printBFS(edges,n,0);
    
}

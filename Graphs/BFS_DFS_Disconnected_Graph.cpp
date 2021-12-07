#include <iostream>
#include <queue>
using namespace std;
// Inside main , we made adjacency matrix , initialized it with 0 , took number of vertices and edges as input . Nothing fancy.
void printDFS(int **edges , int v, int sv , bool* visited ){
    cout<<sv<<" ";
    visited[sv]=1;
    for(int i=0;i<v;i++){
        if(edges[sv][i]==1){
            if(visited[i]){
                continue;
            }//if the edge is present and is not visited,print the vertex
            printDFS(edges , v , i , visited);
        }
    }
}

void printBFS(int** edges , int n , int sv, bool* visited){
    //for bfs no recursion , we'll use queue
  queue<int> pendingVertices;
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
}

//DFS
void DFS(int** edges , int v){
    bool *visited = new bool[v];
    for(int i = 0 ; i < v ; i++){
        visited[i] = false;
    }
    for (int i=0;i<v;i++){
        if(!visited[i]){
            printDFS(edges , v, i, visited);
            }
    }   
    delete [] visited;
}

//BFS
void BFS(int** edges, int v){
    bool *visited = new bool[v];
    for(int i = 0 ; i < v ; i++){
        visited[i] = false;
    }
    for (int i=0;i<v;i++){
        if(!visited[i]){
            printBFS(edges , v, i, visited);
            }
    }
    delete [] visited;
}


int main(){
int v;
int e;
cin>>v>>e;
int** edges = new int*[v];
//vXv matrix initialising
for(int i=0;i<v;i++){
    edges[i] = new int[v];
    for(int j=0;j<v;j++){
        edges[i][j] = 0;
    }
}
//taking edges as input so loop till e
for(int i=0;i<e;i++){
    int f,s;
    cin>>f>>s;
    edges[f][s] =1;
    edges[s][f] =1;
}
cout<<"DFS"<<endl;
DFS(edges,v);
cout<<"\nBFS"<<endl;
BFS(edges,v);
}
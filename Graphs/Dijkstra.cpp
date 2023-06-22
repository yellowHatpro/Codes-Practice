#include <iostream>
#include <climits>
using namespace std;

int findMinVertex(int *distance , bool* visited , int n){
    int minVertex = -1;
    for(int i = 0 ; i < n ; i++){
        if(!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;
}

void dijkstra (int** edges , int n){
    int* distance = new int[n];
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++) {
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    distance[0] = 0;
    for(int i =0 ;i<n-1;i++){
        int minVertex = findMinVertex(distance,visited,n);
        visited[minVertex] = true;
        for(int j=0;j<n;j++){
            if(edges[minVertex][j]!= 0 && !visited[j]){
                int dist = distance[minVertex] + edges[minVertex][j];
                if(dist < distance[j]){
                    distance[j] = dist;
                }
            }

        }
    }
    for(int i = 0 ; i < n ; i++){
        if(distance[i] == INT_MAX){
            cout<<"Vertex "<<i+1<<": There is no path from the source to the destination"<<endl;
            }
        else{
                  cout<<"Vertex "<<i+1<<": shortest distance is "<<distance[i]<<endl;
            }
     

    }
    delete[] distance;
    delete[] visited;

}
int main(){
    cout<<"Welcome to Dijkstra's Algorithm"<<endl;
    cout<<"Ashutosh Aswal BTCSE20103119"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    int n;//n is the number of vertices
    int e;//e is the number of edges
        cout<<"Enter the number of vertices: ";

    cin>>n;
    cout<<"Enter the number of edges: ";
    cin>>e;
    cout<<"Note that the 1st vertex is the start vertex from which the paths are to be calculated"<<endl;
    int** edges = new int*[n];
    for(int i = 0 ; i < n ; i++){
        edges[i] = new int[n];
        for(int j = 0 ; j < n ; j++){
            edges[i][j] = 0;
        }
    }
    cout<<"Enter the edges in the form of (source,destination,weight)"<<endl;
    for(int i = 0 ; i < e ; i++){
        int f , s , weight; //f is from , s is to , weight is the weight of the edge
        cout<<"edge "<<i+1<<" : ";
        cin>>f>>s>>weight;
        f--;
        s--;
        edges[f][s] = weight;
        edges[s][f] = weight;
       
    }
    cout<<endl;
    dijkstra(edges,n);

    for(int i = 0 ; i < n ; i++){
        delete[] edges[i];
    }

    cout<<endl;
    return 0;
}


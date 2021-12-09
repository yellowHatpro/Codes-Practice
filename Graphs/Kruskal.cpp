#include <iostream>
#include <algorithm>
using namespace std;
/*🅺🆁🆄🆂🅺🅰🅻❜🆂 🅰🅻🅶🅾🆁🅸🆃🅷🅼
It is a greedy algorithm
In a Minimum Spanning Tree, Vertices are n, Edges are n-1.
Kruskal says pick edges one by one , starting from the edge with the smallest weight.
*/
//1. Cycle Detection
//Cycle Detection by using Union Find O(V)

class Edge{
    public:
    int source;
    int dest;
    int weight;
};
bool compare(Edge e1 , Edge e2){
    return e1.weight < e2.weight;//for increasing order
}
int findParent(int v , int *parent){
    if (parent[v] == v){
        return v;
    }
    return findParent(parent[v] , parent);
}
void kruskals(Edge *input , int n , int E){
    //1.Sort the input array wrt weights ascending order
    sort(input,input+E , compare );//3rd argument is the comparator

    Edge *output = new Edge[n-1];
    int *parent  = new int[n];
    for(int i=0;i<n;i++){
        parent[i] = i;
    }

    int count =0; // how many edges have been processed
    int i = 0; // index of current edge that is being processed
    while(count!=n-1){
        Edge currentEdge = input[i];
        //Check if we can add the current edge in MST or not 
        int sourceParent = findParent(currentEdge.source,parent);
        int destParent = findParent(currentEdge.dest, parent);
        if(sourceParent!=destParent){
            output[count]  = currentEdge;
            count++;
            parent[sourceParent] = destParent;
        }
        i++;
    }

    //Print the MST
    for(int i=0;i<n-1;i++){
        if(output[i].source < output[i].dest){
            cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
        }
        else{
        cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;

    }
    }
}
int  main(){
    int n ,E;
    cin>>n>>E;
    Edge* input = new Edge[E];
    for(int i=0;i<E;i++){
        int s,d,w;
        cin>>s>>d>>w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }
    //kruskal's algorithm implementation
    kruskals(input,n,E);
    }


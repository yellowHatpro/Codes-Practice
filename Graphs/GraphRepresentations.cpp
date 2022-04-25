//
// Created by ashu on 25-04-2022.
//


//Mostly used are Adjacency Matrix and Adjacency List

/*Adjacency Matrix
 * PROS:
  * Adding an edge, removing an edge, and checking an edge from vertex i to j are O(1)
  * If graph is dense and edges are large, then it is faster to use Adjacency Matrix

* CONS:
 * VxV space requirement of the adjacency matrix makes it inefficient for sparse graphs
 * operations like inEdges and outEdges are expensive

|----|----|----|----|
|  0 |  1 |  0 |  1 |
|----|----|----|----|
|  1 |  0 |  1 |  0 |
|----|----|----|----|
|  0 |  1 |  0 |  1 |
|----|----|----|----|
|  0 |  0 |  1 |  0 |
|----|----|----|----|
*/

#include <bits/stdc++.h>
using namespace std;

class GraphForAdjacencyMatrix{
private:
    bool** adjMatrix;
    int numVertices;
public:
    //matrix init with 0
    GraphForAdjacencyMatrix(int vertices){
        numVertices = vertices;
        adjMatrix = new bool*[numVertices];
        for(int i=0;i<numVertices;i++){
            adjMatrix[i] = new bool[numVertices];
            for(int j=0;j<numVertices;j++){
                adjMatrix[i][j] = false;
            }
        }
    }
    //add edge
    void addEdge(int v1, int v2){
        adjMatrix[v1][v2] = true;
        adjMatrix[v2][v1] = true;
    }
    //remove edge
    void removeEdge(int v1, int v2){
        adjMatrix[v1][v2] = false;
        adjMatrix[v2][v1] = false;
    }
    //Print Adjacency Matrix
    void printAdjMatrix(){
        for(int i=0;i<numVertices;i++){
            cout<< i<<": ";
            for(int j=0;j<numVertices;j++){
                cout<<adjMatrix[i][j]<<" ";

            }
            cout<<endl;
        }
    }
    ~GraphForAdjacencyMatrix(){
        for(int i=0;i<numVertices;i++){
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }
};

class GraphForAdjacencyList{
    int numVertices;
    list<int> *adjList;
public:
    GraphForAdjacencyList(int V){
        numVertices = V;
        adjList = new list<int>[numVertices];
    }
    void addEdge(int src, int dest){
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }
    void printAdjList(){
        for(int i=0;i<numVertices;i++){
            cout<<i<<": ";
            for(auto it=adjList[i].begin();it!=adjList[i].end();it++){
                cout<<*it<<" ";
            }
            cout<<endl;
        }
    }
};


int main(){
//    GraphForAdjacencyMatrix g(5);
//    g.addEdge(0,1);
//    g.addEdge(0,2);
//    g.addEdge(1,2);
//    g.addEdge(2,3);
//    g.addEdge(3,4);
//    g.printAdjMatrix();

    GraphForAdjacencyList g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.printAdjList();
    return 0;
}
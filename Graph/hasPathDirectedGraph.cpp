#include<bits/stdc++.h>
using namespace std;

bool pathHelper(int src, int dest ,const vector<vector<int>> &adj ,vector<bool> &visited){
    if(src == dest){
        return true;
    }

    visited[src] = true;

    for(int neighbor : adj[src]){
        if(!visited[neighbor]){
            if(pathHelper(neighbor,dest,adj ,visited)){
                return true;
            }
        }
    }
    return false;
}
bool hasPath(int V ,int src, int dest, const vector<vector<int>> adj){//V = number of Vertices
    vector<bool> visited(V,false);
    return pathHelper(src , dest , adj , visited);
}
int main(){
     int V = 7;
    //adjacency list using vector of vectors
    vector<vector<int>> adj(V);
    //add undirected edges
    auto addEdge = [&](int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    };
    addEdge(0,1);
    addEdge(0,2);
    addEdge(1,3);
    addEdge(2,4);
    addEdge(3,4);
    addEdge(3,5);
    addEdge(4,5);
    addEdge(5,6);

    cout << hasPath(V, 0 , 5, adj) << endl;
    return 0;
}
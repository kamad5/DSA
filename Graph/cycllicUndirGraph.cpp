#include<bits/stdc++.h>
using namespace std;

bool isCyclicUndirectedHelper(int src, int parent, const vector<vector<int>> &adj, vector<bool> &visited){
    visited[src] = true;

    for(int neighbor : adj[src]){
        if(!visited[neighbor]){
            if(isCyclicUndirectedHelper(neighbor,src,adj, visited)){
                return true;
            }
        }else if(neighbor != parent){
            return true;
        }
    }
    return false;
}
//cycle detection
bool isCyclicUndirected(int V, vector<vector<int>> &adj){
    vector<bool> visited(V,false);

    for(int i = 0; i < V; i++){
        if(!visited[i]){
            if(isCyclicUndirectedHelper(i , -1 , adj, visited)){
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int V = 5;
    vector<vector<int>> adj(V);

    auto addEdge = [&](int u , int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    };
    addEdge(0,1);
    addEdge(0,2);
    addEdge(0,3);
    addEdge(1,2);
    addEdge(3,4);

    
    if(isCyclicUndirected(V ,adj)){
        cout<<"cycle exists in the graph"<<endl;
    }else{
        cout<<"cycle doesn't exists in the graph"<<endl;
    }
    return 0;
}
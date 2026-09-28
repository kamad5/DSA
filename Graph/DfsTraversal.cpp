#include<bits/stdc++.h>
using namespace std;

//recursive helper function
void dfsHelper(int curr, const vector<vector<int>> adj, vector<bool> &visited){
    visited[curr] = true;
    cout << curr << " ";

    for(int neighbor : adj[curr]){
        if(!visited[neighbor]){
            dfsHelper(neighbor,adj,visited);
        }
    }
}
   void dfs(int startNode,int V, const vector<vector<int>> &adj){
    vector<bool> visited(V,false);
    cout << "DFS traversal starting from node "<< startNode <<":";
    dfsHelper(startNode,adj, visited);
   }
int main()
{
   int V = 5;
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
    addEdge(1,4);

    dfs(0, V , adj);
    return 0;
}
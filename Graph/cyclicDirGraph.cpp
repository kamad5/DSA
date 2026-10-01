#include<bits/stdc++.h>
using namespace std;

bool isCyclicDirecetedHelper(int src , const vector<vector<int>>& adj, vector<bool> &visited, vector<bool> &recPath){
    visited[src] = true;
    recPath[src] = true;

    for(auto neighbor : adj[src]){
        if(!visited[neighbor]){
            if(isCyclicDirecetedHelper(neighbor, adj , visited, recPath)){
                return true;
            }
        }else if(recPath[neighbor]){
            return true;
        }
    }
    recPath[src] = false;
    return false;
}
// function to handle disconnected component
bool isCyclicDirected(int V, const vector<vector<int>> &adj){
    vector<bool> visited(V,false);
    vector<bool> recPath(V,false);

    for(int i = 0; i < V; i++){
        if(!visited[i]){
            if(isCyclicDirecetedHelper(i , adj , visited, recPath)){
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

    //directed edge
    auto addEdge = [&](int u , int v){
        adj[u].push_back(v);
    };

    addEdge(1,0);
    addEdge(0,2);
    addEdge(2,3);
    addEdge(3,0);

    if(isCyclicDirected(V ,adj)){
        cout<<"cycle exists in the graph"<<endl;
    }else{
        cout<<"cycle doesn't exists in the graph"<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

void dfsHelper(int curr , const vector<vector<int>>& adj, vector<bool>& vis){
    vis[curr] = true;
    cout << curr <<" ";
    
    for(int neighbor : adj[curr]){
        if(!vis[neighbor]){
            dfsHelper(neighbor, adj , vis);
        }
    }
}
//Dfs function handling
void dfs(int V, const vector<vector<int>>& adj){
    vector<bool> vis(V, false);
    int componentCount = 0;

    cout<< "---connected component---"<<endl;

    for(int i = 0; i < V; i++){
        if(!vis[i]){
            componentCount++;
            cout <<"component "<< componentCount << ":";
            dfsHelper(i , adj , vis);
            cout<<endl;
        }
    }
    cout << "total disconnected component"<<componentCount <<endl;
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
    addEdge(1,2);
    addEdge(2,3);

    addEdge(5,4);
    dfs(V, adj) ;
    return 0;
}
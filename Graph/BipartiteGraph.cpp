#include<bits/stdc++.h>
using namespace std;

bool isBipartite(int startNode, int V, const vector<vector<int>>& adj){
    queue<int>q;
    vector<int> color(V,-1);

    color[startNode] = 0;
    q.push(startNode);

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int neighbor : adj[curr]){
            //if neighbor has been not colored
            if(color[neighbor] == -1){
                //assign a opposite color
                color[neighbor] = !color[curr];
                q.push(neighbor);
            }else if(color[neighbor] == color[curr]){
                //if neighbor is already colored with the same color -> not bipartite
                return false;
            }
        }
    }
    return true;
}
int main(){
    int V = 4;
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
    addEdge(2,3);

    if(isBipartite(0 , V , adj)){
        cout<<"Graph is Bipartite"<<endl;
    }else{
        cout<<"Graph is NOT Bipartite" <<endl;
    }
    return 0;
}
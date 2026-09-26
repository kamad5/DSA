#include<bits/stdc++.h>
using namespace std;

void bfs(int startNode, int V, const vector<vector<int>> & adj){
    vector<bool> visited(V,false);
    queue<int> q;

    visited[startNode] = true;
    q.push(startNode);

    cout<<"BFS Traversal : ";
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        for(int neighbor : adj[curr]){
            if(!visited[neighbor]){
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout<<endl;
}
int main(){
    int V = 5;
    //adjacency list using vector of vectors
    vector<vector<int>> adj(V);

    auto addEdge = [&](int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    };
    addEdge(0,1);
    addEdge(0,2);
    addEdge(1,3);
    addEdge(1,4);

    bfs(0, V , adj);
    return 0;
}
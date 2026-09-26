#include<bits/stdc++.h>
#include<utility>
using namespace std;

class Graph{
    int V;    //Number of vertices
    list<pair<int,int>> *l; // Adjacency list storing pair of (neighbour,weight)

    public :
    //constructor
    Graph(int V){
        this->V = V;
        l = new list<pair<int,int>>[V];
    }

    //function to add an wighted edge to the graph(unweighted)
    void addEdge(int u,int v,int wt){
        l[u].push_back({v,wt});
        l[v].push_back({u,wt});
    }

    //function to print the weighted graph
    void print(){
        for(int u = 0; u < V; u++){
            cout<< u << "-->";
            for(auto neighbor : l[u]){
                int v = neighbor.first;
                int  wt= neighbor.second;
                cout << "(Node : " << v << " ,weight: "<< wt <<")";
            }
            cout<<endl;
        }
    }
};

int main(){
    //create a graph with 5 vertices(0 to 4)
    Graph graph(5);
    //adding edge
    graph.addEdge(0,1,4);
    graph.addEdge(1,2,2);
    graph.addEdge(2,3,3);
    graph.addEdge(2,4,7);
    graph.addEdge(1,3,5);

    //print the adjacency list representation
    cout <<"Adjacnet list of the Graph:\n";
    graph.print();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;    //Number of vertices
    list<int> *l; // Adjacency list

    public :
    //constructor
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    //function to add an edge to the graph(unweighted)
    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    //function to print the graph
    void print(){
        for(int u = 0; u < V; u++){
            cout<< u << "-->";
            for(int v : l[u]){
                cout<< v <<",";
            }
            cout<<endl;
        }
    }
};

int main(){
    //create a graph with 5 vertices(0 to 4)
    Graph graph(5);
    //adding edge
    graph.addEdge(0,1);
    graph.addEdge(1,2);
    graph.addEdge(1,3);
    graph.addEdge(2,3);
    graph.addEdge(2,4);

    //print the adjacency list representation
    cout <<"Adjacnet list of the Graph:\n";
    graph.print();
    return 0;
}
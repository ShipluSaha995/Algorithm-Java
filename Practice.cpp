/*undirected garaph adjacency matrix*/

#include <bits/stdc++.h>
using namespace std;

class Graph{
private:
    int V;
    vector<vector<int>> adj;

public:
    Graph(int vertices){
        V=vertices;
        adj.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v){
        adj[u][v]=1;
        adj[v][u]=1;
    }

    void display(){
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                cout<<adj[i][j]<<" ";           
            }
            cout<<"\n";
        }
    }

};

int main(){
    int V, E;
    cin>>V>>E;

    Graph g(V);
    for(int i=0; i<E; i++){
        int u, v;
        cin>>u>>v;
        g.addEdge(u,v);
    }
     g.display();
    return 0;
}


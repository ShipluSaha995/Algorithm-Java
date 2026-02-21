//Topological sort:

/*
Topological sort of a directed graph is a linear ordering of its vertices such that 
every directed edges uv come from vertices u to v, where u comes before v 

1. Graph has to be directed
2. There should be no cycle in the graph

Method:

1. Find the indegree(number of incoming edges) of all vertices.
2. Print all the vertices whose indegree is 0 . 

*/


#include <bits/stdc++.h>
using namespace std;
void topology(int V, vector<vector<int>> & adj){
    vector<int>indegree(V, 0);

    for(int i=0; i<V; i++){
        for(int v:adj[i]){
            indegree[v]++;
        }
    }

    queue<int>q;

    for(int i=0; i<V; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    int count =0;

    while(!q.empty()){
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        count++;

        for(int v : adj[u]){
            indegree[v]--;
            if(indegree[v]==0){
                q.push(v);
            }
        }
    }

    if(count!=V){
        cout<<"cycle found\n";
    }
}

int main(){
    int V,E;
    cin>>V>>E;
    vector<vector<int>>adj(V);

    for(int i=0; i<E; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    
    topology(V, adj);
    return 0;
}
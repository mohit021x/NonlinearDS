#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;

class graph{

    public:
    unordered_map<int, list<int>>adj;

    void addedge(int u, int v, bool direction){

        //add an edge
        adj[u].push_back(v);

        if(direction == 0){
            adj[v].push_back(u);
        }


    }

    void printgraph(){
        for(auto i : adj){
            cout<<i.first<<"->";
            for(auto j : i.second){
                cout<<j<<" , ";
            }

            cout<<endl;
        }
    }


};


int main(){
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;

    int m;
    cout<<"Enter the number of edges: ";
    cin>>m;

    graph g;

    for(int i=0; i<=m; i++){
        int u,v;
        cin>>u>>v;

        g.addedge(u,v,0); //undirected graph
    }

    g.printgraph();

    return 0;
}
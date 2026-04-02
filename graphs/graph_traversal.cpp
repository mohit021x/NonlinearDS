#include<bits/stdc++.h>
using namespace std;

void buildadjmat(int n, int m, vector<vector<int>>&adjmat){
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;

        adjmat[u][v] = 1;
        adjmat[v][u] = 1;
    }
}

void buildadjlist(int n, int m, vector<vector<int>>&adjlist){
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
}

vector<int> bfstraversal(vector<vector<int>>&adjlist){
    vector<int>ans;
    queue<int>q;
    q.push(1);
    vector<int>visited(adjlist.size(), 0);
    visited[1] = 1;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(auto it : adjlist[node]){
            if(!visited[it]){
                q.push(it);
                visited[it] = 1;
            }
        }
    }

    return ans;
}

void graphdfs(int node, vector<int>&dfs, vector<vector<int>>&adjlist, vector<int>&visited){
    dfs.push_back(node);
    visited[node] = 1;

    for(auto it : adjlist[node]){
        if(!visited[it]){
            graphdfs(it, dfs, adjlist, visited);
        }
    }
}

vector<int> dfstraversal(vector<vector<int>>&adjlist){
    int start = 1;
    vector<int>dfs;
    vector<int>visited(adjlist.size(), 0);
    graphdfs(start, dfs, adjlist, visited);

    return dfs;
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>>adjmat(n+1, vector<int>(n+1, 0));
    vector<vector<int>>adjlist(n+1);

    buildadjlist(n,m,adjlist);
    cout<<"Ajacency list: "<<endl;
    for(int i=1; i<adjlist.size(); i++){
        cout<<i<<"->";
        for(int j=0; j<adjlist[i].size(); j++){
            cout<<adjlist[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    vector<int>bfs = bfstraversal(adjlist);
    cout<<"BFS: "<<endl;
    for(int i=0; i<bfs.size(); i++){
        cout<<bfs[i]<<" ";
    }

    cout<<endl;

    vector<int>dfs = dfstraversal(adjlist);
    cout<<"DFS: "<<endl;
    for(int i=0; i<dfs.size(); i++){
        cout<<dfs[i]<<" ";
    }

    return 0;
}
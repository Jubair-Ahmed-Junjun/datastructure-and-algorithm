#include<bits/stdc++.h>
using namespace std;
vector< vector<int> >graph;
vector<int>d;
vector<bool>vis;

void bfs(int s){
    int t;
    queue<int>q;
    q.push(s);
    d[s]=0;
    vis[s]=true;
    while(!q.empty()){
        t=q.front();
        q.pop();
        for(int i=0;i<graph[t].size();i++){
            if(!vis[graph[t][i]]){
                vis[graph[t][i]]=true;
                d[graph[t][i]]=d[t]+1;
                q.push(graph[t][i]);
            }
        }
    }
}

int main()
{
    int n,m,u,v,i,t,j,a;
    cout<<"Enter the no of vertices..";
    cin>>n;

    vis.resize(n+1);
    graph.resize(n+1);
    d.resize(n+1);

    cout<<"\nEnter the number of edges...";
    cin>>m;
    cout<<"\nEnter the edges ...\n";
    for(i=1;i<=m;i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    fill_n(vis.begin(),n+1,false);
    fill_n(d.begin(),n+1,0);
    cout<<"\nEnter the source and the destination...";
    cin>>u>>v;
    bfs(u);
    cout<<"\nThe Shortest distance from u to v is "<<d[v]<<endl;
    return 0;
}

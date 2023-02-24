#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int>adj[],int vis[]){
    vis[node]=1;
    for(auto it: adj[node] )
    {
        if(!vis[it])
        {
            dfs(it,adj,vis);
        }
    }
}

int main()
{
    int n,m,x,y;
    cin>>n>>m;
    vector <int> adj[n+1];
    for(int i=0;i<m;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int vis[n]={0};
    int start=0,count=0;
    vector<int> ls;
    for(int i=1;i<n;i++)
    {
        if(vis[i]==0)
        {
            count++;
            dfs(i,adj,vis);
        }
    }
    cout<<count;
    
}
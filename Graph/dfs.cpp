#include<bits/stdc++.h>
using namespace std;
/*first travell nodes in depth
DFS done with help of recursion and visited array*/
void dfs(int node,vector<int>adj[],int vis[],vector<int> &ls){
    vis[node]=1;
    ls.push_back(node);
    for(auto it: adj[node] )
    {
        if(!vis[it])
        {
            dfs(it,adj,vis,ls);
        }
    }
}
int main()
{
    int n,m,x,y,w;
    cin>>n>>m;
    vector <int> adj[n+1];
    for(int i=0;i<m;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int vis[n]={0};
    int start=0;
    vector<int> ls;
    dfs(start,adj,vis,ls);
    for(auto it: ls)
    cout<<it<<" ";
}

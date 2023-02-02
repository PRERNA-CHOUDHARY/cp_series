#include<bits/stdc++.h>
using namespace std;
/*first travell nodes connected to single node
BFS done with help of queue and visited array*/
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
    vector<int> bfs;
    int vis[n]={0};
    vis[0]=1;
    queue<int> q;
    q.push(0);
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it: adj[node]){
            if(!vis[it])
            {
                vis[it]=1;
                q.push(it);
            }
        }
    }
    for(auto it : bfs)
    cout<<it<<" ";
    return 0;
}
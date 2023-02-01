/* n ->node 
    m->edge
    input will be edge between two node like
    {{1,2}
    {1,5}
    {2,3}} 
    Graph is represented using adjencency matrix or list
*/
/*
    create adj[n+1][n+1] base node is 1
*/

#include<bits/stdc++.h>
using namespace std;

int main()

{
    int n,m,x,y,w;
    cin>>n>>m;
//adjecency matrix
    vector<vector<int>> adj1 (n+1,vector<int>(n+1,0));
    for(int i=0;i<m;i++){
        cin>>x>>y;
        adj1[x][y]=1;
        adj1[y][x]=1;
    }
//adjcency list no weight
    vector<int >adj2[n+1];
    for(int i=0;i<m;i++){
        cin>>x>>y;
        adj2[x].push_back(y);
        adj2[y].push_back(x);   //for undirected graph
    }

//adjcency list with weight and direciton
    vector <pair<int,int>> adj3[n+1];
    for(int i=0;i<m;i++){
            cin>>x>>y>>w;
            adj3[i].push_back(make_pair(y,w));
}
return 0;
}
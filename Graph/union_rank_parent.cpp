#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int>rank,parent;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++)
            parent[i]=i;
    }
    int findParent(int node){
        if(parent[node]==node)
            return node;
        return parent[node]=findParent(parent[node]);
    }
    void unionByRank(int u,int v)
    {
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);
        if(rank[ulp_u]<rank[ulp_v])
            parent[ulp_u]=ulp_v;
        else if(rank[ulp_u]>rank[ulp_v])
            parent[ulp_v]=ulp_u;
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
};

int main()
{
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2 ,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    if(ds.findParent(3)==ds.findParent(7))
    cout<<"same component\n";
    else cout<<"different component\n";
    ds.unionByRank(3,7);
    if(ds.findParent(3)==ds.findParent(7))
    cout<<"same component\n";
    else cout<<"different component\n";
    return 0;
}
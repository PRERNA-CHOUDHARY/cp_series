//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

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


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                int wt=it[1];
                int v= it[0];
                int u=i;
                edges.push_back({wt,{u,v}});
                
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(),edges.end());
        int mstWt=0;
        for(auto it: edges)
        {
            int wt=it.first;
            int adjNode=it.second.second;
            int node=it.second.first;
            if(ds.findParent(node)!=ds.findParent(adjNode))
            {
                mstWt+=wt;
                ds.unionByRank(node,adjNode);
            }
        }
        return mstWt;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
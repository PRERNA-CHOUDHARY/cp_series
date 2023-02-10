/*There are a total of n tasks you have to pick, labeled from 0 to n-1. 
Some tasks may have prerequisites tasks,
 for example to pick task 0 you have to first finish tasks 1, which is expressed as a pair: [0, 1]
Given the total number of n tasks and a list of prerequisite pairs of size m.
 Find a ordering of tasks you should pick to finish all tasks.
Note: There may be multiple correct orders, you just need to return one of them.
 If it is impossible to finish all tasks, return an empty array. 
Returning any correct order will give the output as 1, whereas any invalid order will give the output 0.

USE TOPOLOGY SORT
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int V, int m, vector<vector<int>> prerequisites) 
    {
         // Code here
	    vector <int> adj[V];
	    for(auto it:prerequisites)
	    {
	        adj[it[1]].push_back(it[0]);
	    }
	    int indegree[V]={0};
        queue<int> q;
        int count=0;
        for(int i=0;i<V;i++)
        {
            for(auto it: adj[i])
            {
                indegree[it]++;
            }
        }
        
        for (int i=0;i<V;i++){
            if(indegree[i]==0)
            q.push(i);
        }
        vector<int> seq;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            count++;
            seq.push_back(node);
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }    
        if(count==V) return seq;
        else return {};//code here
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends
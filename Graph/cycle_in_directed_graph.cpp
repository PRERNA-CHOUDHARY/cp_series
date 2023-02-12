//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
  bool check(int node, vector<int> adj[],vector<int> &vis,vector<int>& pathvis)
  {
      vis[node]=1;
      pathvis[node]=1;
      for(auto it : adj[node])
      {
          if(vis[it]==0)
          {
              if(check(it,adj,vis,pathvis)) return true;
          }
          else if(pathvis[it]) return true;
      }
      
      pathvis[node]=0;
      return false;
  }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V,0),
        pathvis(V,0);
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                if (check(i,adj,vis,pathvis)) return true;
            }
        }
        return false;
        
        // code here
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

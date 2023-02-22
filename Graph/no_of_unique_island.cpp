//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
  void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis,vector<pair<int,int>>&vec,int row0,int col0){
      vis[row][col]=1;
      int n=grid.size(),
      m=grid[0].size();
      vec.push_back({row-row0,col-col0});
      int delrow[]={-1,0,1,0},
      delcol[]={0,1,0,-1};
      for(int i=0;i<4;i++){
          int nrow=row+delrow[i];
          int ncol=col+delcol[i];
          if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]){
              dfs(nrow,ncol,grid,vis,vec,row0,col0);
          }
      }
  }
  
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n= grid.size(),
        m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        set <vector<pair<int ,int>>> unique_island;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    vector<pair<int,int>> vec;
                    dfs(i,j,grid,vis,vec,i,j);
                    unique_island.insert(vec);
                }
            }
            
        }
        return unique_island.size();
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends
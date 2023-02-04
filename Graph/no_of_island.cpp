#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void bfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>>& grid){
    vis[row][col]=1;
    int n=grid.size();
    int m=grid[0].size();
    queue <pair<int,int>> q;
    q.push({row,col});
    while(!q.empty())
    {
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        for(int i=-1 ;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                int nrow=r+i;
                int ncol =c+j;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                grid[nrow][ncol]=='1' && !vis[nrow][ncol])
                   { vis[nrow][ncol]=1;
                    q.push({nrow,ncol});}
            }
        }
    }
}
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
    int m=grid[0].size();
         vector<vector<int>> vis(n,vector<int>(m,0));
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j] && grid[i][j]=='1')
            {
                count++;
                bfs(i,j,vis,grid);
            }
        }
    }
    return count;
    }
};
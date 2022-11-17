#include<bits/stdc++.h>
// count no of unique path to reach right-bottom from top left...
/*
recursion 
f(v,i,j){
  if(v[i][j]==-1) return 0;  // obstical 
  (i==0 && j==0 ) return 1;
  if(i<0 || j<0) return 0;
  up=f(v,i-i,j);
  left=f(v,i,j-1);
  return (up+left);

}
*/
using namespace std;
int result(vector<vector<int>>v,int m,int n,vector<vector<int>> dp){
    if (m==0 && n==0) return 1;
    if(m<0 || n<0) return 0;
    if(v[m][n]==-1) return 0;
    if(dp[m][n]!=-1) return dp[m][n];
    int up= result(v,m-1,n,dp);
    int left=result(v,m,n-1,dp);
    return dp[m][n]=up+left;
}


int result_tabulation(vector<vector<int>>v,int m,int n){
 int dp[m][n];
for(int i=0;i<m;i++)
{
    for(int j=0;j<n;j++)
    {
        int up=0,left=0;
        if(i==0 && j==0  && v[i][j]!=-1) dp[i][j]=1;

        else{
        if(i>0 && v[i][j]!=-1)  up =dp[i-1][j];
        if(j>0 && v[i][j]!=-1)  left =dp[i][j-1];
        dp[i][j]= up +left;
        }
    }
}
cout<<dp[m-1][n-1];
}

int main()
{
  int m=3,n=3;
 vector<vector<int>> mat{
    {0,0,0},
    {0,-1,0},
    {0,0,0}
 };
  vector<vector<int>>  dp(m,vector<int> (n,-1));
 cout<<result(mat,m-1,n-1,dp)<<endl;
 result_tabulation(mat,m,n);

return 0;
}


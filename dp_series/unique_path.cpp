#include<bits/stdc++.h>

// count no of unique path to reach right-bottom from top left...
/*
recursion 
f(i,j){
  (i==0 && j==0 ) return 1;
  else if(i<0 || j<0) return 0;
  up=f(i-i,j);
  left=f(i,j-1);
  return (up+left);
}
*/
using namespace std;
int result(int m,int n,vector<vector<int>> dp){
    if (m==0 && n==0) return 1;
    if(m<0 || n<0) return 0;
    if(dp[m][n]!=-1) return dp[m][n];
    int up= result(m-1,n,dp);
    int left=result(m,n-1,dp);
    return dp[m][n]=up+left;
}


int result_tabulation(int m,int n){
 int dp[m][n];
for(int i=0;i<m;i++)
{
    for(int j=0;j<n;j++)
    {
        int up=0,left=0;
        if(i==0 && j==0 ) dp[i][j]=1;
        else{
        if(i>0)  up =dp[i-1][j];
        if(j>0)  left =dp[i][j-1];
        dp[i][j]= up +left;
        }
    }
}
cout<<dp[m-1][n-1];
}

int main()
{
  int m=2,n=2;
  vector<vector<int>>  dp(m,vector<int> (n,-1));
 cout<<result(m-1,n-1,dp)<<endl;
 result_tabulation(m,n);

return 0;
}


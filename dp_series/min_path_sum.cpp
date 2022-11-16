#include<bits/stdc++.h>
using namespace std;

int min_path(vector<vector<int>> v,int m,int n,vector<vector<int>> &dp)
{
    if(m==0 && n==0) return v[0][0];
    if(m<0 || n<0) return 1e9;
    if( dp[m][n]!=-1) return dp[m][n];
    int up=min_path(v,m-1,n,dp)+v[m][n];
    int left=min_path(v,m,n-1,dp)+v[m][n];
    return dp[m][n]=(min(up,left));
}
int main(){
    vector<vector<int>> v{{5,1,16},
    {2,10,1}};
    int m=v.size(),n=v[0].size();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    cout<<min_path(v,m-1,n-1,dp);
}
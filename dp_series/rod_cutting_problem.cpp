#include<bits/stdc++.h>
using namespace std;

int rod_cut(vector<int> val,int i,int n,vector<vector<int>>&dp)
{
    if(i==0) return n*val[i];
    if(dp[i][n]!=-1) return dp[i][n];
        int not_take=rod_cut(val,i-1,n,dp)+0;
        int take=-1e9;
        int rodlen=i+1;
        if(rodlen<=n) take=rod_cut(val,i,n-rodlen,dp)+val[i];
        return dp[i][n]= max(take ,not_take);

}
int main()
{
  vector<int> val={2,5,7,8,10};
 
    int n=val.size();
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    cout<<rod_cut(val,n-1,n,dp);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
/* divide array into two partition of equal sum*/

bool target_sum(vector<int>v,int i,int target,vector<vector<int>>&dp)
{
    if(0==target )
     return 1;
     if(dp[i][target]!=-1) return dp[i][target];
    if(target<0 || i <0) return 0;
    return dp[i][target]= (target_sum(v,i-1,target-v[i],dp) ||target_sum(v,i-1,target,dp));
}

int main(){

    vector<int> v{6,3,6,3,0};
    int n=v.size();
    int target=0;
    for(int i=0;i<n;i++) target+=v[i];
    (target&1)?target=1e8:target=target/2;
    // cout<<target;
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    cout<<target_sum(v,n-1,target,dp);
    return 0;
}
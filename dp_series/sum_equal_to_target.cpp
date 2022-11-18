#include<bits/stdc++.h>
using namespace std;
/* find sum equal to target*/
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
    int target=9;
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    cout<<target_sum(v,n-1,target,dp);
    return 0;
}
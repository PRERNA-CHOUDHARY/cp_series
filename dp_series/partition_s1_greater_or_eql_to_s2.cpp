#include<bits/stdc++.h>
using namespace std;
/*Partition a set into two subsets such 
that the difference of subset sums is minimum.*/
int target_sum(vector<int>v,int i,int target,vector<vector<int>>&dp)
{
    if(0==target )
     return 1;
     if(i==0) return v[0]==target;
     if(dp[i][target]!=-1) return dp[i][target];
    if(target<0 || i <0) return 0;
    return dp[i][target]= (target_sum(v,i-1,target-v[i],dp) +target_sum(v,i-1,target,dp));
}
int main()
{
    
    vector<int> v{1,2,3};
    int n=v.size();
    // int target=1;
    int d=1;
    int sum=1;
    for(auto i:v)
    sum+=i;

    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
    if(sum-d<0 || (sum-d)%2) cout<<0;
    else
    cout<<target_sum(v,n-1,(sum-d)/2,dp);
    return 0;
    

}
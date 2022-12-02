#include<bits/stdc++.h>
using namespace std;
int unbounded_knapsack(vector<int> val,vector<int> wt,int i,int w, vector<vector<int>>  &dp)
{
    // if(w<0 || i<0) return 0;   // this base case is also correct;
    if(i==0)
       return ((int)(w/wt[i]) * val[i]);
    if(dp[i][w]!=-1 ) return dp[i][w];
    int not_pick=unbounded_knapsack(val,wt,i-1,w,dp)+0;
    int pick=-1e9;
    if(wt[i]<=w) pick=unbounded_knapsack(val,wt,i,w-wt[i],dp)+val[i];
    return dp[i][w]=max(pick,not_pick);
}
int main()
{
  vector<int> val={30,40,50},wt={3,2,4};
 int w=5;
    int n=val.size();
    vector<vector<int>> dp(n,vector<int>(w+1,-1));
    cout<<unbounded_knapsack(val,wt,n-1,w,dp);
    return 0;
}
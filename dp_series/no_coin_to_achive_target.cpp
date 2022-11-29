#include<bits/stdc++.h>
using namespace std;
/* all set of coin to achive target*/
/*if there is infinite supply of somthing then 
while taking it dont change the index*/
int set_of_coin(vector<int> v,int i,int target,vector<vector<int>> &dp)
{
    // if(target==v[i]) return 1;
    if(i==0){
    return (target%v[i]);
    }
    if(dp[i][target]!=-1) return dp[i][target];
    int not_take= 0+set_of_coin(v,i-1,target,dp);
    int take=0;
    if(v[i]<=target) take=1+set_of_coin(v,i,target-v[i],dp);
    return dp[i][target]=(take+not_take);
}

int main()
{
  vector<int> val={1,2,3};
 int target=3;
    int n=val.size();
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    cout<<set_of_coin(val,n-1,target,dp);
    return 0;
}
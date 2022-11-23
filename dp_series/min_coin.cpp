#include<bits/stdc++.h>
using namespace std;
/* min no. coin to achive target*/
/*if there is infinite supply of somthing then 
while taking it dont change the index*/
int min_count(vector<int> v,int i,int target,vector<vector<int>> &dp)
{
    if(target==v[i]) return 1;
    if(dp[i][target]!=-1) return dp[i][target];
    if(i==0){
    if (target%v[i]==0) return target/v[i];
    else return 1e8;
    }
    if(i<0 || target<0 ) return 0;
    int not_take= 0+min_count(v,i-1,target,dp);
    int take=1e9;
    if(v[i]<=target) take=1+min_count(v,i,target-v[i],dp);
    return dp[i][target]=min(take,not_take);
}
int main()
{
  vector<int> val={9,6,5,1};
 int target=11;
    int n=val.size();
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    cout<<min_count(val,n-1,target,dp);
    return 0;
}
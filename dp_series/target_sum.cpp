#include<bits/stdc++.h>
using namespace std;
/* achive target by assigning sign to array elements*/
int mod= 1e9+7;
int assign_sign(vector<int> v, int i, int target, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (target == 0 && v[0] == 0)
            return 2;
        if (target == 0 || target == v[0])
            return 1;
        return 0;
    }
    
    if (dp[i][target] != -1)
        return dp[i][target];

    int nottake = assign_sign(v, i - 1, target, dp);
    int take = 0;
    if (v[i] <= target)
        take = assign_sign(v, i - 1, target - v[i], dp);
    return dp[i][target] =(take + nottake)%mod;
}


int main()
{
  vector<int> val={9,6,5,1};
 int target=11;
    int n=val.size();
    int sum=0;
    for(int i=0;i<n;i++)
    sum+=val[i];
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    if(sum-target<0 || (sum-target)%2) cout<<0;
    else
    cout<<assign_sign(val,n-1,(sum-target)/2,dp);
    return 0;
}
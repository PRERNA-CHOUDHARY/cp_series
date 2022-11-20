#include<bits/stdc++.h>
using namespace std;
/*Partition a set into two subsets such 
that the difference of subset sums is minimum.*/
bool target_sum(vector<int>v,int target,vector<vector<int>>&dp)
{
    int n=v.size();
    for(int i=0;i<n;i++) dp[i][0]=1;
    if(v[0]<=target) dp[0][v[0]]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=target;j++)
        {
            bool nottake=dp[i-1][j];
            bool take =false;
            if(v[i]<=j) take=dp[i-1][j-v[i]];
            dp[i][j]=nottake|take;
        }
    }
}
bool min_diff(vector<int>v,int i,vector<vector<int>> &dp)
{

}
int main()
{
    vector<int> v{3,7,2};
    int n=v.size(),sum=0;
    for(int i=0;i<n;i++)
    sum+=v[i];
    cout<<sum<<endl;
    vector<vector<int>> dp(n,vector<int> (sum+1,0));
    target_sum(v,sum,dp);
    for(auto i:dp)
    {for(auto j:i)
        cout<<j;
        cout<<'\n';}

    int mini =1e9;
    for(int s1=0;s1<=sum/2;s1++)
    {
        if(dp[n-1][s1]==1)
            mini=min(mini,abs((sum-s1)-s1));
    }
    cout<<mini;

}
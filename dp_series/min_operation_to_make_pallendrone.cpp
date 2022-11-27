#include<bits/stdc++.h>
using namespace std;
//to find only len use int dp instead of string dp;
int ans(string s1,string s2,int i,int j,vector<vector<int>> &dp){
    if (i<0 || j<0) return 0; 
    if(dp[i][j]!=-1) return dp[i][j];
    int match=-1e9,not_match=-1e9;
    if(s1[i]==s2[j])
       match=ans(s1,s2,i-1,j-1,dp)+1;
      if(s1[i]!=s2[j])  not_match= max(ans(s1,s2,i-1,j,dp),ans(s1,s2,i,j-1,dp));
    return dp[i][j]=max(not_match,match);
}

int main()
{
    string s1="prerna";
    string s2=s1,res="";
    reverse(s2.begin(),s2.end());
    vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,-1));
    cout<<(s1.size()-ans(s1,s2,s1.length()-1,s2.length()-1,dp));

}
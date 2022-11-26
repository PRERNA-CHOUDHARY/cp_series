#include<bits/stdc++.h>
using namespace std;
//to find only len use int dp instead of string dp;
string ans(string s1,string s2,int i,int j,vector<vector<string>> &dp){
    if (i<0 || j<0) return ""; 
    if(dp[i][j]!="#") return dp[i][j];
    string match="",not_match="";
    if(s1[i]==s2[j])
       match=ans(s1,s2,i-1,j-1,dp)+s1[i];
      if(s1[i]!=s2[j])  not_match= max(ans(s1,s2,i-1,j,dp),ans(s1,s2,i,j-1,dp));
    return dp[i][j]=max(not_match,match);
}

int main()
{
    string s1="prerna";
    string s2=s1,res="";
    reverse(s2.begin(),s2.end());
    vector<vector<string>> dp(s1.length()+1,vector<string>(s2.length()+1,"#"));
    cout<<ans(s1,s2,s1.length()-1,s2.length()-1,dp);

}
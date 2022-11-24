
#include<bits/stdc++.h>
using namespace std;
/*consecutive string...*/


int main()
{
    string s1="prerna",s2="prnrea",res="";
    vector<vector<string>> dp(s1.length()+1,vector<string>(s2.length()+1,""));
   for(int i=0;i<=s1.length();i++)  dp[0][i]="";
   for(int j=0;j<=s2.length();j++) dp[j][0]="";
   for(int i=1;i<=s1.length();i++)
   {
   for(int j=1;j<=s2.length();j++)
   {
    if(s1[i-1]==s2[j-1]) {
        dp[i][j]=s1[i]+dp[i-1][j-1];
        res=max(res,dp[i][j]);}
     else dp[i][j]="";
   }

   }
   cout<<res;
}
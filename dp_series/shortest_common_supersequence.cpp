/*shortest common supersequence: brute+groot = bgruoote*/

#include<bits/stdc++.h>
using namespace std;



int main()
{
    string s1="brute",s2="groot",res="";
    vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,-1));
    for(int i=0;i<=s1.length();i++)  dp[0][i]=0;
   for(int j=0;j<=s2.length();j++) dp[j][0]=0;
   for(int i=1;i<=s1.length();i++)
   {
   for(int j=1;j<=s2.length();j++)
   {
    if(s1[i-1]==s2[j-1]) {
        dp[i][j]=1+dp[i-1][j-1];
        }
     else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);;
   }

   }
    // for(auto i:dp)
    // {
    //     for(auto j:i)
    //     cout<<j <<"  ";
    //     cout<<endl;
    // }
    int i=s1.length() ,j=s2.length();
    while(i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            res+=s1[i-1];
            i--;
            j--;
        }
        else if (dp[i-1][j]>dp[i][j-1])         
        {
            res+=s1[i-1];
            i--;
        }
        else {
            res+=s2[j-1];
            j--;
        }
    }
    while(i>0)
    {
        res+=s1[i-1];
        i--;
    }
    while(j>0)
    {
        res+=s2[j-1];
        j--;
    }
    cout<<s1.length()+s2.length()-dp[s1.length()][s2.length()];
    cout<<endl;
    reverse(res.begin(),res.end());
    cout<<res;
}
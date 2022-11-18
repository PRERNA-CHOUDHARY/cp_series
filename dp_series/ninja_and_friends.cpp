#include<bits/stdc++.h>
using namespace std;
/*
alice ,bob two friends collects chocolats in 2d matrix, 
find max chocolates can be collected 
,if there is colision only one can pick from that cell
alis is at (0,0) bob at(0,n-1)
drxn allowes: down ,right dia,left dia*/
/*
step1: express in term of (i1,j1) & (i2,j2);
i1=i2=i;
step2: try all stuff
step3: covert to dp;
*/
/*
recursive approach
f(i,j1,j2){}
if(j1<0 || j1>=m ||j2<0 ||j2>=m) return -1e8; 

if(i==m-1) 
{
    if (j1!=j2)return v[i,j1]+v[i,j2];
    else return v[i,j1];
}
 for(int k=-1;k<=+1;k++)
 {
    for(int l=-1;l<=+1;l++)
    {
        if(j1==j2) v[i][j1]+ f(i+1,j1+k,l+j2);
        else v[i][j1]+v[i][j2]+ f(i+1,j1+k,l+j2)
    }
 }
 }
*/

int find_sum(vector<vector<int>> v,int i,int j1,int j2,vector<vector<vector<int>>> &dp)
{
    if(j1<0 ||j1>=v[0].size()||j2<0|| j2>=v[0].size())
        return -1e8;
    if(i==v.size()-1) 
    {
        if(j1==j2) return v[i][j1];
        else return v[i][j2]+v[i][j1];
    }
    if(dp[i][j1][j1]!=-1) return dp[i][j1][j2];
    int maxm=-1e8;
    for(int dj1=-1;dj1<=1;dj1++)
    {
        for(int dj2=-1;dj2<=1;dj2++)
        {
            int left=0;
            if(j1==j2)  left=v[i][j1];
            else left=v[i][j1]+v[i][j2];
            left+=find_sum(v,i+1,j1+dj1,j2+dj2,dp);
            maxm=max(maxm,left);
        }
    }
    return dp[i][j1][j2]=maxm;
}
int main()
{
    vector <vector<int>> v{
    {2,3,1,2 },
    {3,4,2,2},
    {5,6,3,5}};
    int m=v.size();
    int n=v[0].size();
    vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
    cout<<find_sum(v,0,0,n-1,dp);
    return 0;
    
}
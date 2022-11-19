/*
find max path starting from any point
1   2   10   4
100 3   2    1 
1   1   20   2
1   2   2    1


moves allowed :/ | \
*/

/*recurssion approach
f(int i,int j)
{
   if(i==0) return v[i][j];
   if(i<0 || j<0 || j>m ) return -1e9;  
    int left_dia= v[i][j]+ f(i-1,j-1);
    int right_dia=v[i][j]+ f(i-1,j+1);
    int st=v[i][j]+f(i-1,j);
    return max(st,max(left_dia,right_dia));
}
main()
{
    int x=-1e9;
 for i =0 to m-1
 {
    x=max(x,f(n-1,i));
 }
 }
*/
#include<bits/stdc++.h>
using namespace std;

int max_sum_path(vector <vector<int>> v,int i,int j,vector <vector<int>> &dp)
{
   if(i==0) return v[i][j];
   if(i<0 || j<0 || j>=v.size() ) return -1e9;  
   if(dp[i][j]!=-1) return dp[i][j];
    int left_dia= v[i][j]+ max_sum_path(v,i-1,j-1,dp);
    int right_dia=v[i][j]+ max_sum_path(v,i-1,j+1,dp);
    int st=v[i][j]+max_sum_path(v,i-1,j,dp);
    return dp[i][j]= max(st,max(left_dia,right_dia));
}
int find_path(vector <vector<int>> v,int i,int j,vector <vector<int>> &dp)
{
    int ans=-1e9;
    for(int k=0;k<v.size();k++)
    {
        ans=max(ans,max_sum_path(v,v.size()-1,k,dp));
    }
    return ans;
}
int main()
{
    vector <vector<int>> v{{1,2,10,4},
    {100,3,2,1 },
    {1,1,20,2},
    {1,2,2,1}};
    int m=v.size();
    int n=v[0].size();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    cout<<find_path(v,m-1,n-1,dp);
    return 0;
}
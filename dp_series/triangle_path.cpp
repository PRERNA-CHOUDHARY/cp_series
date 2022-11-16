#include<bits/stdc++.h>
using namespace std;
/*
1
2 3
4 6 7
8 9 6 10
*/

int find_min_path(vector <vector<int>> v,int i,int j,int m,int n,vector <vector<int>> & dp)
{
    if(i==m) return v[m][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int  dia=v[i][j]+find_min_path(v,i+1,j+1,m,n,dp);
    int  down=v[i][j]+find_min_path(v,i+1,j,m,n,dp);
    return dp[i][j]= min(dia,down);
}
int main()
{
    vector <vector<int>> v{{1},{2,3},{4,6,7},{8,9,6,10}};
    int m=v.size();
    int n=v[m-1].size();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    cout<<find_min_path(v,0,0,m-1,n-1,dp);
}
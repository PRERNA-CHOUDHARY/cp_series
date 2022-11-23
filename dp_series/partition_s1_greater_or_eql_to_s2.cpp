#include <bits/stdc++.h>
using namespace std;
/*Partition a set into two subsets such
that the difference of subset sums is minimum.*/
int target_sum(vector<int> v, int i, int target, vector<vector<int>> &dp)
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

    int nottake = target_sum(v, i - 1, target, dp);
    int take = 0;
    if (v[i] <= target)
        take = target_sum(v, i - 1, target - v[i], dp);
    return dp[i][target] = take + nottake;
}
int main()
{

    vector<int> v{1, 2, 4};
    int n = v.size();
    // int target=1;
    int d = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += v[i];
    // cout<<sum;
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    if(sum-d<0 || (sum-d)%2) cout<<0;
    else
        cout << target_sum(v, n - 1, (sum - d) / 2, dp);
    return 0;
}
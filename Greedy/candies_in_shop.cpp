//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int k)
    {
        sort(candies,candies+N);
        
    
    int minSum=0,maxSum=0;
    int j=N-1;
    
    for(int i=0;i<=j;i++)
    {
        minSum+=candies[i];
        j-=k;
    }
    j=0;
    for(int i=N-1;i>=j;i-- )
    {
        maxSum+=candies[i];
        j+=k;
    }
    return {minSum,maxSum};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    long long minCost(long long arr[], long long n) {
        
        priority_queue<long long,vector<long long>,greater<long long >>q(arr,arr+n);
        long long cost=0;
        while(q.size()>1)
        {
            long long r1=q.top();
            q.pop();
            long long r2=q.top();
            q.pop();
            cost+=r1+r2;
            q.push(r1+r2);
        }
        return cost;
    }
    
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
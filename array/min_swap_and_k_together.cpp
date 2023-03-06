//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
        int tot_sm_ele=0,maxm=0,each_win_sm=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=k)
                tot_sm_ele++;
        }
        for(int i=0;i<tot_sm_ele;i++)
        {
            if(arr[i]<=k)
            {
                each_win_sm++;
            }
        }
        maxm=max(maxm,each_win_sm);
        for(int j=tot_sm_ele;j<n;j++)
        {
            if(arr[j]<=k) each_win_sm++;
            if(arr[j-tot_sm_ele]<=k) each_win_sm--;
            maxm=max(maxm,each_win_sm);
        }
        return tot_sm_ele-maxm;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends
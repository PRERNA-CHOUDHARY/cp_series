//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        stack<long long>st;
        st.push(0);
        vector<long long> nse(n,n),pse(n,-1);
        for(int i=1;i<n;i++)
        {
            while(!st.empty() && arr[i]<arr[st.top()])
            {
                nse[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())
        {
            nse[st.top()]=n;
            st.pop();
        }
        st.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() && arr[i]<arr[st.top()])
            {
                pse[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())
        {
            pse[st.top()]=-1;
            st.pop();
        }
        long long maxArea=INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxArea=max(maxArea,arr[i]*(nse[i]-pse[i]-1));
        }
        return maxArea;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string S)
    {
        string rev="",temp="";
        for(int i=0;i<S.size();i++){
            if(S[i]=='.')
            {
                rev=rev+temp;
                rev+=".";
                temp="";
            }
            else{
                temp=S[i]+temp;
            }
        }
        rev=rev+temp;
        return rev;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
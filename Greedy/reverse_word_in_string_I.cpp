//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        string rev="",temp="";
        for(int i=S.size();i>=0;i--){
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
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        if(p=="") return "-1";
        vector<int>fs(256,0),fp(256,0);
        int dist_p=0;
        for(int i=0;i<p.size();i++)
        {
            if(fp[p[i]]==0)
                dist_p++;
            fp[p[i]]++;
        }
        int c=0,st=0,e=0;
        for(int i=0;i<s.size();i++)
        {
            fs[s[i]]++;
            if(fs[s[i]]==fp[s[i]])
            c++;
            if(c==dist_p)
            {
                e=i;
                break;
            }
            
        }
        if(c<dist_p) return "-1";
        int ans_s=st,ans_e=e,minm=e-st+1;
        while(e<s.size())
        {
            while(fs[s[st]]>fp[s[st]])
            {
                fs[s[st]]--;
                st++;
                if((e-st+1)<minm)
                {
                    minm=e-st+1;
                    ans_s=st;
                    ans_e=e;
                }
                
            }
            e++;
            if(e<s.size()) fs[s[e]]++;
            
        }
        if((e-st+1)<minm)
                {
                    minm=e-st+1;
                    ans_s=st;
                    ans_e=e;
                }
        return s.substr(ans_s,minm);
        
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
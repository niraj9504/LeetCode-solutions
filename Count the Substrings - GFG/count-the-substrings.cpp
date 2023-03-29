//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string s)
    {
        int l=0,h=0,n=s.size(),ans=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=i;j<n;j++){
                if(s[j]>='a' && s[j]<='z')cnt++;
                else cnt--;
                
                if(cnt==0)ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends
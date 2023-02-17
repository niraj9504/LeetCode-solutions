//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string s){
        // code here 
        int l=0,r=0,ans=0,cnt=0;
        while(r<n){
            if(s[r]=='O')cnt++;
            if(cnt>m){
                while(cnt>m && l<r){
                    if(s[l]=='O')cnt--;
                    l++;
                }
            }
            ans=max(ans,(r-l+1));
            r++;
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
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
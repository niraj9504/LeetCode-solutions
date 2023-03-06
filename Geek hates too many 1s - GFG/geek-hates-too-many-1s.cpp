//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    int noConseBits(int n) {
        // code here
        string s="";
        while(n){
            if(n&1)s+='1';
            else{
                s+='0';
            }
            n=n>>1;
        }
        // reverse(s.begin(),s.end());
        // cout<<s<<endl;
        int ans=0,z=s.size();
        for(int i=z-1;i>=2;i--){
            if(s[i]=='1'){
                ans|=(1<<i);
                if(s[i-1]=='1')s[i-2]='0';
            }
        }
        if(s[1]=='1')ans|=2;
        if(s[0]=='1')ans|=1;
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends
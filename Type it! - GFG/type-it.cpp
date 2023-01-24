//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        // code here
        int n=s.size(),ans=n;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(s[j]==s[i]){
                    int l=i,r=j,cnt=0;
                    while(r<n && l<j && s[l++]==s[r++])cnt++;
                    ans=min(ans,n-cnt+1);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends
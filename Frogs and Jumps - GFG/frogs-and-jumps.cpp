//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int n, int l, int f[]) {
        // Code here
        vector<int> vis(l+1,0);
        for(int i=0;i<n;i++){
            if(f[i]<=l && !vis[f[i]]){
                for(int j=f[i];j<=l;j+=f[i])vis[j]=1;
            }
        }
        for(auto it:vis){
            if(it==1)l--;
        }
        return l;
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int dp[100001][3];
    int solve(vector<vector<int>> &c,int i,int n,int p){
        if(i==n){
            return 0;
        }
        if(dp[i][p]!=-1)return dp[i][p];
        int x=INT_MAX;
        for(int j=0;j<3;j++){
            if(j!=p-1)
            x=min(x,(solve(c,i+1,n,j+1)+c[i][j]));
        }
        return dp[i][p]=x;
    }
    int minCost(vector<vector<int>> &c, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(c,0,n,0);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends
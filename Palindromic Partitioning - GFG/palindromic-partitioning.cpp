//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPal(int i,int j,string s){
        while(i<j){
            if(s[i++]!=s[j--])return false;
        }
        return true;
    }
    int dp[501][501];
    int solve(int i,int j,string s){
        if(i>=j || isPal(i,j,s))return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=s.size();
        for(int k=i;k<j;k++){
            int left,right;
            if(dp[i][k]!=-1){
                left=dp[i][k];
            }
            else{
                left=solve(i,k,s);
                dp[i][k]=left;
            }
            if(dp[k+1][j]!=-1){
                right=dp[k+1][j];
            }
            else{
                right=solve(k+1,j,s);
                dp[k+1][j]=right;
            }
            int temp=left+right+1;
            ans=min(ans,temp);
        }
        return dp[i][j]=ans;
    }
    int palindromicPartition(string s)
    {
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        if(isPal(0,n-1,s))return 0;
        return solve(0,n-1,s);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
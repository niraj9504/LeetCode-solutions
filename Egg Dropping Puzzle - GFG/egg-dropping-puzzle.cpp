//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[201][201];
    int solve(int e,int f){
        if(e==1 || f<=1)return f;
        if(dp[e][f]!=-1)return dp[e][f];
        int l=0,h=f,ans=INT_MAX;
        while(l<=h){
            int mid=(l+h)>>1;
            int top=solve(e,f-mid);
            int bottom=solve(e-1,mid-1);
            if(top>=bottom){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
            int x=max(top,bottom)+1;
            ans=min(ans,x);
        }
        return dp[e][f]=ans;
    }
    int eggDrop(int e, int f) 
    {
        memset(dp,-1,sizeof(dp));
        return solve(e,f);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends
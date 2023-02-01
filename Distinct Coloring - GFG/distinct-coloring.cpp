//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    // int dp[50001];
    // //prev is idx -> 0,1,2
    // long long int solve(int i,int n,int r[],int g[],int b[],int prev){
    //     if(i>=n)return 0;
    //     if(prev==-1){
    //         int val=min(min(r[i],g[i]),b[i]);
    //         prev=(val==r[i])?0:((val==g[i])?1:2);
    //         return solve(i+1,n,r,g,b,prev)+val;
    //     }
    //     if(prev==0){
    //         int val=min(g[i],b[i]);
    //         prev=(val==g[i])?1:2;
    //         return solve(i+1,n,r,g,b,prev)+val;
    //     }
    //     else if(prev==1){
    //         int val=min(r[i],b[i]);
    //         prev=(val==r[i])?0:2;
    //         return solve(i+1,n,r,g,b,prev)+val;
    //     }
    //     int val=min(g[i],r[i]);
    //     prev=(val==g[i])?1:0;
    //     return solve(i+1,n,r,g,b,prev)+val;
    // }
    long long int distinctColoring(int N, int r[], int g[], int b[]){
        // code here 
        // return solve(0,N,r,g,b,-1);
        long long int dp[N][3];
        dp[0][0]=r[0];dp[0][1]=g[0];dp[0][2]=b[0];
        for(int i=1;i<N;i++){
            dp[i][0]=r[i]+min(dp[i-1][1],dp[i-1][2]);
            dp[i][1]=g[i]+min(dp[i-1][2],dp[i-1][0]);
            dp[i][2]=b[i]+min(dp[i-1][0],dp[i-1][1]);
        }
        return min(dp[N-1][0],min(dp[N-1][1],dp[N-1][2]));
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends
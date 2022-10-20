class Solution {
public:
    int n,m;
    // int solve(int i,int j,string &s1,string &s2){
    //     if(i==n || j==m){
    //         return 0;
    //     }
    //     int x=0;
    //     if(s1[])
    // }
    int longestCommonSubsequence(string s1, string s2) {
        n=s1.size(),m=s2.size();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        // solve(0,0,s1,s2);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);;
                }
            }
        }
        return dp[n][m];
    }
};
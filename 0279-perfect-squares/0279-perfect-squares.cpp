class Solution {
public:
    int inf=1e8;
    int dp[10001];
    int solve(int n){
        if(n<0)return inf;
        if(n<=3)return n;
        if(dp[n]!=-1)return dp[n];
        int x=inf;
        for(int i=sqrt(n);i>=1;i--){
            x=min(x,1+solve(n-(i*i)));
        }
        return dp[n]=x;
    }
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};
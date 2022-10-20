class Solution {
public:
    int inf=1e8;
    int coinChange(vector<int>& coins, int W) {
        int n=coins.size();
        int dp[n+1][W+1];
        memset(dp,0,sizeof(dp));
        // for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int i=1;i<=W;i++)dp[0][i]=inf;
        for(int i=1;i<=W;i++){
            if(i%coins[0]==0){
                dp[1][i]=i/coins[0];
            }
            else dp[1][i]=inf;
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j<=W;j++){
                if(j>=coins[i-1]){
                    dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][W]>=inf?-1:dp[n][W];
    }
    
};
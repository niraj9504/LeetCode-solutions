class Solution {
public:
    int n;
    int dp[101][101];
    int solve(int r,int c,vector<vector<int>> &mat){
        if(r==n)return 0;
        if(r>n || c<0 || c>=n)return 1e5;
        if(dp[r][c]!=-1)return dp[r][c];
        return dp[r][c]=min(solve(r+1,c-1,mat),min(solve(r+1,c,mat),solve(r+1,c+1,mat))) +mat[r][c];
    }
    int minFallingPathSum(vector<vector<int>>& mat) {
        n=mat.size();
        memset(dp,-1,sizeof(dp));
        int sum=INT_MAX;
        for(int i=0;i<n;i++){
            sum=min(sum,solve(0,i,mat));
        }
        return sum;
    }
};
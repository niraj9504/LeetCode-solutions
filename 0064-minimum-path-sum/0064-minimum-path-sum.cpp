class Solution {
public:
    int m,n;
    int dp[201][201];
    int solve(int i,int j,vector<vector<int>> &grid){
        if(i>=m || j>=n)return INT_MAX;
        if(dp[i][j]!=-1)return dp[i][j];
        if(i==m-1 && j==n-1){
            return grid[i][j];
        }
        return dp[i][j]=min(solve(i+1,j,grid),solve(i,j+1,grid))+grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,grid);
    }
};
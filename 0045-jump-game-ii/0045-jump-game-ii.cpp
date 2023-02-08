class Solution {
public:
    int dp[10001];
    int solve(int i,vector<int> &nums){
        if(i>=nums.size()-1)return 0;
        int x=1e8;
        if(dp[i]!=-1)return dp[i];
        for(int j=1;j<=nums[i];j++){
            x=min(solve(i+j,nums)+1,x);
        }
        return dp[i]=x;
    }
    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,nums);
    }
};
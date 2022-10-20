class Solution {
public:
    int dp[2501][2501];
    int solve(int i,vector<int> &nums,int prev){
        if(i==nums.size())return 0;
        int x=0,y=0;
        if(prev!=-1 && dp[i][prev]!=-1)return dp[i][prev];
        x=solve(i+1,nums,prev);
        if(prev==-1 || nums[i]>nums[prev]){
            y=solve(i+1,nums,i)+1;
        }
        return prev!=-1? dp[i][prev]=max(x,y):max(x,y);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,nums,-1);
    }
};
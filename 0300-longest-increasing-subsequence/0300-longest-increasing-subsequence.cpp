class Solution {
public:
    int dp[2501][2501];
    int solve(int prev,int i,vector<int> &nums){
        if(i==nums.size())return 0;
        int x=0;
        if(prev!=-1 && dp[prev][i]!=-1)return dp[prev][i];
        x=solve(prev,i+1,nums);
        //pick
        if(prev==-1 || nums[i]>nums[prev]){
            x=max(x,solve(i,i+1,nums)+1);
        }
        return prev==-1? x:dp[prev][i]=x;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 1;
        memset(dp,-1,sizeof(dp));
        return solve(-1,0,nums);
    }
};
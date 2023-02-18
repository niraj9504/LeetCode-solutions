class Solution {
public:
    long long countFairPairs(vector<int>& nums, int l, int u) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long ans=0;
        
        for(int i=0;i<n;i++){
            int up=upper_bound(nums.begin()+i+1,nums.end(),u-nums[i])-nums.begin();
            int low=lower_bound(nums.begin()+i+1,nums.end(),l-nums[i])-nums.begin();
            ans+=up-low;
        }
        return ans;
    }
};
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n=nums.size();
        long long sum=0,ans=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            long long avg=ceil(sum*1.0/(i+1));
            ans=max(ans,avg);
        }
        return ans;
    }
};
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> map;
        long long i=0,j=0,ans=0,curr=0;
        for(;j<k;j++){
            map[nums[j]]++;
            curr+=nums[j];
        }
        ans=curr;
        if(map.size()!=k)ans=0;
        for(;j<n;j++){
            map[nums[i]]--;
            curr-=nums[i];
            if(map[nums[i]]<=0)map.erase(nums[i]);
            i++;
            map[nums[j]]++;
            curr+=nums[j];
            if(map.size()==k){
                ans=max(ans,curr);
            }
        }
        return ans;
    }
};
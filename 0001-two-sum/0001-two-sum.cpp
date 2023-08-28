class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        int n=nums.size();
        if(n<2)return {};
        for(int i=0;i<n;i++){
            int x=t-nums[i];
            for(int j=i+1;j<n;j++){
                if(nums[j]==x)return {i,j};
            }
        }
        return {};
    }
};
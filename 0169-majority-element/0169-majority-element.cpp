class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,n=nums.size();
        while(i<=n/2){
            if(nums[i]==nums[i+n/2])return nums[i];
            i++;
        }
        return -1;
    }
};
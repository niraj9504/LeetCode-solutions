class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //O(1) space
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[abs(nums[i])-1]>0)
            nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
        }
        for(int i=1;i<=n;i++){
            if(nums[i-1]>0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
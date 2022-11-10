class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(auto i:nums){
            int idx=abs(i)-1;//abs(i) give original value at nums(without -ve sign)
            if(nums[idx]<0){
                ans.push_back(abs(i));
            }
            nums[idx]=-nums[idx];//equal and -ve(it will remain same but -ve shows bool true if that position occurs twice)
        }
        return ans;
    }
};
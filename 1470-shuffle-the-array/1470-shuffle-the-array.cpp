class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2*n);
        int i=0,j=n,idx=0;
        while(i<n){
            ans[idx++]=nums[i++];
            ans[idx++]=nums[j++];
        }
        return ans;
    }
};
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> count(k);
        int ans=0,prefix=0;
        count[0]=1;
        for(auto it:nums){
            prefix=(prefix+it%k+k)%k;
            ans+=count[prefix]++;
        }
        return ans;
    }
};
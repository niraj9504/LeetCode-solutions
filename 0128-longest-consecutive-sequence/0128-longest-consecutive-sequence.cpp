class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> map;
        if(nums.size()<=1)return nums.size();
        int ans=1;
        for(auto it:nums)map[it]=1;
        for(auto it:nums){
            if(map.find(it-1)==map.end()){
                int curr=1;
                while(map.find(it+1)!=map.end()){
                    curr++;
                    it++;
                }
                ans=max(ans,curr);
            }
        }
        return ans;
    }
};
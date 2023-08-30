class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        int n=nums.size();
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            
            if(map.find(t-nums[i])!=map.end()){
                return {map[t-nums[i]],i};
            }
            map[nums[i]]=i;
        }
        return {};
    }
};
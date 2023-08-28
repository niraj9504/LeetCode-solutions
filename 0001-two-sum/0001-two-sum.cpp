class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        int n=nums.size();
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            int x=t-nums[i];
            if(map.find(x)!=map.end())return {i,map[x]};
            map[nums[i]]=i;
        }
        return {};
    }
};
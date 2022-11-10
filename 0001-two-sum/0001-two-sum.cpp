class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            if(map.find(t-nums[i])!=map.end()){
                return {map[t-nums[i]],i};
            }
            else{
                map[nums[i]]=i;
            }
        }
        return {-1,-1};
    }
};
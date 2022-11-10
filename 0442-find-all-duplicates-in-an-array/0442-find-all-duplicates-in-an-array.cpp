class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> map;
        vector<int> ans;
        for(auto i:nums){
            if(map.find(i)!=map.end())ans.push_back(i);
            map.insert(i);
        }
        return ans;
    }
};
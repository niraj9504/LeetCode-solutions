class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> map(nums.begin(),nums.end());
        nums.clear();
        for(int i=1;i<=n;i++){
            if(map.find(i)==map.end())nums.push_back(i);
        }
        return nums;
    }
};
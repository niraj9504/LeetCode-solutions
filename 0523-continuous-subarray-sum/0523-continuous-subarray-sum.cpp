class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int sum=0;
        map.insert({0,-1});
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            sum%=k;
            auto x=map.find(sum);
            if(x!=map.end()){
                if(i-map[sum]>1)
                    return true;
            }
            else{
                map.insert({sum,i});
            }
        }
        return false;
    }
};
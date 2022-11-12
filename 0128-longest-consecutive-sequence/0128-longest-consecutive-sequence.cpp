class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> map;
        int ans=0;
        for(auto it:nums){
            map[it]=1;
        }
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
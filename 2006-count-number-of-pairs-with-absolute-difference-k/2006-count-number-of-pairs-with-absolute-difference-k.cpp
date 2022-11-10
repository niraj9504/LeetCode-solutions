class Solution {
public:
    int countKDifference(vector<int>& nums, int t) {
        unordered_map<int,int> map;
        int cnt=0;
        for(auto it:nums){
            if(map.find(t+it)!=map.end() || map.find(it-t)!=map.end()){
                cnt+=map[t+it];
            }
            if(map.find(it-t)!=map.end()){
                cnt+=map[it-t];
            }
            map[it]++;
        }
        return cnt;
    }
};
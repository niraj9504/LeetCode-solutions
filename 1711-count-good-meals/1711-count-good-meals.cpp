class Solution {
public:
    int mod=1e9+7;
    using ll=long long;
    int countPairs(vector<int>& nums) {
        // sort(d.begin(),d.end());
        unordered_map<int,int> map;
        ll cnt=0;
        for(int i=0;i<nums.size();i++){
            int t=1;
            for(int j=0;j<22;j++){
                if(map.find(t-nums[i])!=map.end()){
                    cnt+=map[t-nums[i]];
                }
                t=t<<1;
            }
            map[nums[i]]++;
        }
        return cnt%mod;
    }
};
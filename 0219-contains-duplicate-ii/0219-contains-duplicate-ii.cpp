class Solution {
public:
    using pi=pair<int,int>;
    bool containsNearbyDuplicate(vector<int>& nums, int x) {
        int n=nums.size();
        vector<pi> temp;
        for(int i=0;i<n;i++){
            temp.push_back({nums[i],i});
        }
        sort(temp.begin(),temp.end());
        for(int i=1;i<n;i++){
            int a=temp[i-1].first,b=temp[i].first;
            int k=temp[i-1].second,j=temp[i].second;
            if(a==b && abs(j-k)<=x)return true;
        }
        return false;
    }
};
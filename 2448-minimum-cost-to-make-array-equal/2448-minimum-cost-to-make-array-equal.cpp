class Solution {
public:
    using ll=long long;
    ll paisa(ll m,vector<int> &nums,vector<int> &cost){
        ll kitna=0,n=nums.size();
        for(int i=0;i<n;i++){
            kitna+=(ll)(cost[i]*(abs(nums[i]-m)));
        }
        return kitna;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll l=*min_element(nums.begin(),nums.end());
        ll h=*max_element(nums.begin(),nums.end());
        ll ans=LONG_MAX;
        while(l<=h){
            ll mid=(l+h)/2;
            ll a=paisa(mid-1,nums,cost);
            ll b=paisa(mid+1,nums,cost);
            if(a>b){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
            ans=min(ans,paisa(mid,nums,cost));
        }
        return ans;
    }
};
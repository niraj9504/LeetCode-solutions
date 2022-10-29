class Solution {
public:
    int earliestFullBloom(vector<int>& p, vector<int>& g) {
        int n=p.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({g[i],p[i]});
        }
        sort(v.begin(),v.end(),[&](pair<int,int> &a,pair<int,int> &b){
            return a.first>b.first;
        });
        int ans=0,curr=0;
        for(auto [a,b] : v){
            curr+=b;
            ans=max(ans,a+curr);
        }
        return ans;
    }
};
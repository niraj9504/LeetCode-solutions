class Solution {
public:
    using pi=pair<int,int>;
    int largestOverlap(vector<vector<int>>& m1, vector<vector<int>>& m2) {
        int n=m1.size();
        vector<pi> v1,v2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(m1[i][j])v1.push_back({i,j});
                if(m2[i][j])v2.push_back({i,j});
            }
        }
        map<pi,int> map;
        int ans=0;
        for(auto [i1,j1]:v1){
            for(auto [i2,j2]:v2){
                map[{i2-i1,j2-j1}]++;
                ans=max(ans,map[{i2-i1,j2-j1}]);
            }
        }
        return ans;
    }
};
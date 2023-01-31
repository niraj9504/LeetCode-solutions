class Solution {
public:
    using pi=pair<int,int> ;
    int n;
    // int dp[1001][10001];
    vector<vector<int>> dp;
    int solve(int i,int prev,vector<pi> &sa){
        if(i>=n)return 0;
        int x=0;
        //pick
        if(prev!=-1 && dp[i][prev]!=-1)return dp[i][prev];
        if(prev==-1 || sa[i].first<=sa[prev].first){
            x=sa[i].first+solve(i+1,i,sa);
        }
        //not pick
        if(prev==-1)return max(x,solve(i+1,prev,sa));
        return dp[i][prev]=max(x,solve(i+1,prev,sa));
    }
    int bestTeamScore(vector<int>& s, vector<int>& a) {
        n=s.size();
        vector<pair<int,int>> sa;
        for(int i=0;i<n;i++){
            sa.push_back({s[i],a[i]});
        }
        sort(sa.begin(),sa.end(),[&](pi &a,pi &b){
            if(a.second==b.second)return a.first>b.first;
            return a.second>b.second;
        });
        // memset(dp,-1,sizeof(dp));
        dp.resize(n+1,vector<int> (n+1,-1));
        return solve(0,-1,sa);
    }
};
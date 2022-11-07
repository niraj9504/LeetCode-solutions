class Solution {
public:
    using ll=long long;
    ll dp[101][10001];
    long long solve(int i,int j,vector<int> &robot,vector<int> &posn){
        if(i==robot.size())return 0;
        if(j==posn.size())return 1e16;
        if(dp[i][j]!=-1)return dp[i][j];
        ll pick=solve(i+1,j+1,robot,posn)+abs(posn[j]-robot[i]);
        //here removing the extra calculation
        // int m=upper_bound(posn.begin(),posn.end(),posn[j])-posn.begin();
        ll not_pick=solve(i,j+1,robot,posn);
        return dp[i][j]=min(pick,not_pick);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& fac) {
        vector<int> posn;//position 
        memset(dp,-1,sizeof(dp));
        sort(robot.begin(),robot.end());
        sort(fac.begin(),fac.end());
        for(auto it:fac){
            int x=it[0],y=it[1];
            for(int i=1;i<=y;i++){
                posn.push_back(x);
            }
        }
        return solve(0,0,robot,posn);
    }
};
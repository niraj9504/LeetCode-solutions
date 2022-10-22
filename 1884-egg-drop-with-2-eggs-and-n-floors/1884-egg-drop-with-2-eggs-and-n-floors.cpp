class Solution {
public:
    int dp[3][1001];
    int solve(int e,int f){
        if(e==1 || f<=1)return f;
        if(dp[e][f]!=-1)return dp[e][f];
        int l=0,h=f,ans=INT_MAX;
        while(l<=h){
            int mid=(l+h)>>1;
            int left=solve(e-1,mid-1);
            int right=solve(e,f-mid);
            if(left<=right){
                l=mid+1;
            }
            else h=mid-1;
            
            int x=max(left,right)+1;
            ans=min(x,ans);
        }
        return dp[e][f]=ans;
    }
    int twoEggDrop(int f) {
        memset(dp,-1,sizeof(dp));
        return solve(2,f);
    }
};
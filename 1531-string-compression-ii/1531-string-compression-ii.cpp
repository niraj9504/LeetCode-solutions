class Solution {
public:
    int dp[127][127];
    inline int compress(int n){
        if(n==1)return 0;
        else if(n<10)return 1;
        else if(n<100)return 2;
        return 3;
    }
    int n;
    int solve(int i,string &s,int k){
        if(k<0)return 101;
        if(i>=s.size() || s.size()-i<=k)return 0;
        if(dp[i][k]!=-1)return dp[i][k];
        int cnt[26]={0};
        int most=0,ans=INT_MAX;
        for(int j=i;j<s.size();j++){
            cnt[s[j]-'a']++;
            int freq=cnt[s[j]-'a'];
            most=max(most,freq);
            //chars to be deleted => (j-i+1-most)
            ans=min(ans,1+compress(most) + solve(j+1,s,k-(j-i+1-most)));//total length=j-i+1 ,most+1 =>common
        }
        return dp[i][k]=ans;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp,-1,sizeof(dp));
        n=s.size();
        return solve(0,s,k);
    }
};
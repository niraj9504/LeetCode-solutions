class Solution {
public:
    int mod=1e9+7;
    int dp[1001][2];
    int solve(int i,int n,bool prevGap){
        if(i>n)return 0;
        if(i==n)return prevGap==false;
        if(dp[i][prevGap])return dp[i][prevGap];
        if(prevGap==false){
            return dp[i][prevGap]=(solve(i+2,n,false)+solve(i+1,n,false)+2LL*solve(i+2,n,true))%mod;
        }
        return dp[i][prevGap]=(solve(i+1,n,true)+solve(i+1,n,false))%mod;
        
    }
    int numTilings(int n) {
        //filling start to end
        /*
        {i,bool} bool -> if there any left gap is present previous
        curr idx=i
        
        1. -- => --
                 --  => i+2 , prev is totally filled (false)
        2. |
           |  => i+1,true
        
        3.  _ 
           |
           |     => i+2, but i+1 is not filled, true
           
        4. |
           |
            -    => i+2, true
        5. reverse L and mirror image of 3
        (not consider this because we have started filling from start to end)
        important => for 3
        a) filling can be like horizontal line is used,i->i+1 and gap is created at top (true)
        b) reverse L can perfectly fill the gap, i->i+1, false
        */
        memset(dp,0,sizeof(-1));
        return solve(0,n,false);
    }
};
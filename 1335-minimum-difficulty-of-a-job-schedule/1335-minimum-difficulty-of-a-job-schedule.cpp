class Solution {
public:
    int dp[301][11];
    int solve(int i,vector<int> &job,int d){
        int n=job.size();
        if(d==0){
            int maxi=job[i];
            for(int j=i;j<n;j++)maxi=max(maxi,job[j]);
            return maxi;
        }
        if(dp[i][d]!=-1)return dp[i][d];
        int mini=INT_MAX,currMax=job[i];
        for(int j=i;j<n-d;j++){
            currMax=max(currMax,job[j]);
            mini=min(mini,solve(j+1,job,d-1)+currMax);
        }
        return dp[i][d]=mini;
        
    }
    int minDifficulty(vector<int>& job, int d) {
        int n=job.size();
        if(d>n)return -1;
        memset(dp,-1,sizeof(dp));
        return solve(0,job,d-1);
    }
};

//     public int minDifficulty(int[] k, int d) {
//         if(d > k.length) return -1;
//         return dfs(k, d-1, 0);
//     }
    
//     private int dfs(int[] k, int d, int pos) {
// 		//base case
//         if(d == 0) {
//             int max = k[pos];
//             for(int i = pos; i < k.length; i++) max = Math.max(max, k[i]);
//             return max;
//         } 
		
//         int max = Integer.MIN_VALUE;
//         int min = Integer.MAX_VALUE;
		
// 		//try out all ranges for that day
//         for(int i = pos; i < k.length-d; i++) {
//             max = Math.max(max, k[i]);
//             min = Math.min(min, max + dfs(k, d-1, i+1));
//         }
// 		return min;
//     }
// class Solution {
// public:
//     int n,m;
//     vector<int> dir={0,1,0,-1,0};
//     int solve(int i,int j,vector<vector<int>> &grid,int k){
//         if(i==m-1 && j==n-1){
//             return 0;
//         }
//         if(k<0)return 1e8;
//         int x=1e8;
//         for(int k=0;k<4;k++){
//             int r=i+dir[k],c=j+dir[k+1];
//             //if wall
//             if(r>=m || r<0 || c>=n || c<0)continue;
//             if(grid[r][c])
//                 x=min(x,solve(r,c,grid,k-1)+1);
//             else {
//                 x=min(x,solve(r,c,grid,k)+1);
//             }
//         }
//         return x==1e8?-1:x;
//     }
//     int shortestPath(vector<vector<int>>& grid, int k) {
//         m=grid.size(),n=grid[0].size();
//         return solve(0,0,grid,k);
//     }
// };

class Solution {
public:
    int dp[42][42][1609];
    const static int MAX = 1e7;
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        return help(grid, grid.size() - 1, grid[0].size() - 1, k, k);
    }
    
    int help(vector<vector<int>>& grid, int x, int y, int z, int k){
        
        //Reached destination
        if(x == 0 && y  == 0)return 0;
        
        //Already visited/calculated
        if(dp[x][y][z]) return dp[x][y][z];
        
        //Cant remove any more obstacles
        if(grid[x][y] == 1 && z == 0)return MAX;
        
        //Manhattan optimization
        if(z >= x + y)return dp[x][y][z] = x+y;
        
        //Make sure to take direction left and up before right and top
        vector<vector<int>> dirs = {{-1,0}, {0,-1}, {1,0}, {0,1}};
        
        //Setting dp[x][y][z] to MAX so that it does not gets calculated again 
        dp[x][y][z] = MAX;
        
        for(auto dir:dirs){
            //DFS valid condition
            if(x + dir[0] >= 0 && x + dir[0] < grid.size() && y + dir[1] >=0 && y + dir[1] < grid[0].size() ){
                dp[x][y][z] = min(dp[x][y][z], help(grid, x + dir[0], y + dir[1], z - grid[x][y], k) + 1);
            }
        }
        //If not possible
        if(z == k && x == grid.size() - 1 && y == grid[0].size() - 1 && dp[x][y][z] == MAX)return -1;
        return dp[x][y][z];
        
    }
	};
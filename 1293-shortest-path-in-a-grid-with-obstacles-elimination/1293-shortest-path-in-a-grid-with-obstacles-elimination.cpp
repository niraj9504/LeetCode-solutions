class Solution {
public:
    //bfs
    using vi=vector<int>;
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vi> vis(m,vi(n,-1));
        vector<int> dir={0,1,0,-1,0};
        queue<vi> q;
        q.push({0,0,0,k});//x,y,cnt,obstacle
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int i=it[0],j=it[1];
            //out of bound
            if(i>=m || i<0 || j>=n || j<0)continue;
            //destination
            if(i==m-1 && j==n-1)return it[2];
            //obstacle
            if(grid[i][j]==1){
                if(it[3])it[3]--;
                else continue;
            }
            //not found better case than prev case
            //https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/discuss/712992/C++-or-BFS/1097084
            if(vis[i][j]!=-1 && vis[i][j]>=it[3])continue;
            
            vis[i][j]=it[3];
            
            for(int d=0;d<4;d++){
                q.push({i+dir[d],j+dir[d+1],it[2]+1,it[3]});
            }
        }
        return -1;
    }
};
class Solution {
public:
    using pi=pair<int,int> ;
    int m,n;
    void solve(int rr,int cc,vector<vector<int>> &grid){
        int dir[]={0,1,0,-1,0};
        queue<pi> q;
        q.push({rr,cc});
        grid[rr][cc]=0;
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int r=p.first+dir[i],c=p.second+dir[i+1];
                if(r<m && r>=0 && c<n && c>=0 && grid[r][c]){
                    q.push({r,c});
                    grid[r][c]=0;
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        m=grid.size(), n=grid[0].size();
        for(int i=0;i<m;i++){
            if(grid[i][0])
                solve(i,0,grid);
            if(grid[i][n-1])
                solve(i,n-1,grid);
        }
        for(int i=0;i<n;i++){
            if(grid[0][i])
                solve(0,i,grid);
            if(grid[m-1][i])
                solve(m-1,i,grid);
        }
        int cnt=0;
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(grid[i][j])cnt++;
            }
        }
        return cnt;
    }
};
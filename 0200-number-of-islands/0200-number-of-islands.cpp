class Solution {
public:
    using pi=pair<int,int>;
    
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size(),cnt=0,dir[]={0,1,0,-1,0};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    queue<pi> q;
                    q.push({i,j});
                    grid[i][j]='0';
                    while(!q.empty()){
                        auto x=q.front();q.pop();
                        for(int d=0;d<4;d++){
                            int r=x.first+dir[d],c=x.second+dir[d+1];
                            if(r<m && r>=0 && c<n && c>=0 && grid[r][c]=='1'){
                                q.push({r,c});
                                grid[r][c]='0';
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};

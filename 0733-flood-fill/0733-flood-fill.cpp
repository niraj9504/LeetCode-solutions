class Solution {
public:
    #define pi pair<int,int>
    vector<vector<int>> floodFill(vector<vector<int>>& image, int r, int c, int x) {
        queue<pi> q;
        int dir[]={0,1,0,-1,0}, v=image[r][c],m=image.size(),n=image[0].size();
        image[r][c]=x;
        if(x==v)return image;
        q.push({r,c});
        while(!q.empty()){
            pi p=q.front();q.pop();
            for(int i=0;i<4;i++){
                r=p.first;c=p.second;
                r+=dir[i];c+=dir[i+1];
                if(r<m && r>=0 && c<n && c>=0 && image[r][c]==v){
                    image[r][c]=x;
                    q.push({r,c});
                }
            }
        }
        return image;
    }
};
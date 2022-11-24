class Solution {
public:
    vector<int> dir={0,1,0,-1,0};
    int m,n,p;
    bool search(int r,int c,vector<vector<char>> &mat,string &w,int k){
        if(k==p)return true;
        char ch=mat[r][c];
        mat[r][c]='-1';
        bool fl=false;
        for(int i=0;i<4;i++){
            int x=r+dir[i],y=c+dir[i+1];
            if(x>=m || x<0 || y>=n || y<0)continue;
            if(mat[x][y]==w[k]){
                fl|=search(x,y,mat,w,k+1);
            }
        }
        mat[r][c]=ch;
        return fl;
    }
    bool exist(vector<vector<char>>& board, string word) {
        //m*n cell, word=> find
        char ch=word[0];
        m=board.size(),n=board[0].size(),p=word.size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==ch){
                    if(search(i,j,board,word,1))return true;
                }
            }
        }
        return false;
    }
};
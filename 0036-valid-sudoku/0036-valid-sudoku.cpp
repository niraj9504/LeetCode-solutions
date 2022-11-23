class Solution {
public:
    bool isPoss(int r,int c,vector<vector<char>> &board){
        char ch=board[r][c];
        for(int i=0;i<9;i++){
            if(i!=c && board[r][i]==ch)return false;
            if(i!=r && board[i][c]==ch)return false;
            if(((3*(r/3)+i/3)!=r || (3*(c/3)+i%3)!=c) && board[3*(r/3)+i/3][3*(c/3)+i%3]==ch)return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(isPoss(i,j,board)==false)return false;
                }
            }
        }
        return true;
    }
};
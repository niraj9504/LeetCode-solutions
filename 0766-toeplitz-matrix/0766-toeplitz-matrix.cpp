class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        for(int k=1;k<m;k++){
            int i=k,j=1;
            while(i<m && j<n){
                if(mat[i][j]!=mat[i-1][j-1])return false;
                i++;j++;
            }
        }
        for(int k=2;k<n;k++){
            int i=1,j=k;
            while(i<m && j<n){
                if(mat[i][j]!=mat[i-1][j-1])return false;
                i++;j++;
            }
        }
        return true;
    }
};
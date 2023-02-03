//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    using pi=pair<int,int>;
    pi ans;
    void solve(int i,int j,vector<vector<int>> &mat,int r,int c,char dir){
        if(i>=r || j>=c || i<0 || j<0)return;
        if(dir=='r'){
            ans={i,j};
            if(mat[i][j]==0){
                solve(i,j+1,mat,r,c,dir);
            }
            else{
                mat[i][j]=0;
                solve(i+1,j,mat,r,c,'d');
            }
        }
        else if(dir=='d'){
            ans={i,j};
            if(mat[i][j]==0){
                solve(i+1,j,mat,r,c,dir);
            }
            else{
                mat[i][j]=0;
                solve(i,j-1,mat,r,c,'l');
            }
        }
        else if(dir=='l'){
            ans={i,j};
            if(mat[i][j]==0){
                solve(i,j-1,mat,r,c,dir);
            }
            else{
                mat[i][j]=0;
                solve(i-1,j,mat,r,c,'u');
            }
        }
        else{
            ans={i,j};
            if(mat[i][j]==0){
                solve(i-1,j,mat,r,c,dir);
            }
            else{
                mat[i][j]=0;
                solve(i,j+1,mat,r,c,'r');
            }
        }
    }
    pair<int,int> endPoints(vector<vector<int>> mat, int r, int c){
        ans={0,0};
        solve(0,0,mat,r,c,'r');
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends
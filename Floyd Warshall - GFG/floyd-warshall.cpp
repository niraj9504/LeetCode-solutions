//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&mat){
	    int n=mat.size();
	    vector<vector<int>> dis(n,vector<int>(n,1e9));
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(mat[i][j]!=-1)dis[i][j]=mat[i][j];
	        }
	    }
	    for(int k=0;k<n;k++){
	        for(int i=0;i<n;i++){
    	        for(int j=0;j<n;j++){
    	            if(dis[i][j]>dis[i][k]+dis[k][j]){
    	                dis[i][j]=dis[i][k]+dis[k][j];
    	            }
    	        }
    	    }
	    }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(dis[i][j]!=1e9)mat[i][j]=dis[i][j];
	        }
	    }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
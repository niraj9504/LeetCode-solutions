//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<int> m;
    vector<bool> used;
    bool solve(int u,vector<vector<int>> &g){
        for(int v=0;v<g[0].size();v++){
            if(g[u][v] && !used[v]){
                used[v]=true;
                if(m[v]<0 || solve(m[v],g)){
                    m[v]=u;
                    return true;
                }
            }
        }
        return false;
    }
	int maximumMatch(vector<vector<int>>&g){
	    // Code here
	    int mm=g.size();
	    int n=g[0].size();
	    int N=max(n,mm);
	    int ans=0;
	    m.assign(N,-1);
	    for(int i=0;i<mm;i++){
	        used.assign(N,false);
	        if(solve(i,g))ans++;
	    }
	    return ans;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>G(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> G[i][j];
		}
		Solution obj;
		int ans = obj.maximumMatch(G);
		cout << ans << "\n";    
	}
	return 0;
}
// } Driver Code Ends
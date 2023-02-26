//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int node,int &v,int &e,vector<vector<int>> &adj,vector<int> &vis){
        vis[node]=1;
        v++;
        e+=adj[node].size();
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,v,e,adj,vis);
            }
        }
    }
    int findNumberOfGoodComponent(int n, vector<vector<int>>& adj) {
        vector<int> vis(n+1,0);
        int ans=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                int v=0,e=0;
                dfs(i,v,e,adj,vis);
                if(e/2==(v*(v-1))/2)ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends
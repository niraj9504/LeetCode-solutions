class Solution {
public:
    bool dfs(int node,vector<int> &vis,vector<int> &dfsvis,vector<int> adj[]){
        vis[node]=1;
        dfsvis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,dfsvis,adj))return true;
            }
            else if(dfsvis[it]){
                return true;
            }
        }dfsvis[node]=0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& graph) {
        vector<int> adj[n];
        for(auto it:graph){
            int u=it[1],v=it[0];
            adj[u].push_back(v);
        }
        vector<int> vis(n,0),dfsvis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,vis,dfsvis,adj))return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                queue<int> q;
                q.push(i);
                color[i]=0;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(auto it:adj[node]){
                        if(color[it]==-1){
                            q.push(it);
                            color[it]=1-color[node];
                        }
                        else if(color[it]==color[node])return false;
                    }
                }
            }
        }
        return true;
    }
};
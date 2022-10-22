class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& graph) {
        vector<int> adj[n];
        for(auto it:graph){
            int u=it[1],v=it[0];
            adj[u].push_back(v);
        }
        vector<int> indegree(n);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }
        int count=0;
        while(!q.empty()){
            int x=q.front();q.pop();
            count++;
            for(auto it:adj[x]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(count==n)return true;
        return false;
    }
};
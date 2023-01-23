class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // vector<int> adj[n];
        vector<int> indegree(n),outdegree(n);
        for(auto it:trust){
            // adj[it[0]].push_back(it[1]);
            indegree[it[1]-1]++;
            outdegree[it[0]-1]++;
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==n-1 && outdegree[i]==0){
                return i+1;
            }
        }
        return -1;
    }
};
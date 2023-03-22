// class Solution {
// public:
//     using pi=pair<int,int>;
//     vector<int> parent,rank;
//     int findPar(int u){
//         if(parent[u]==u)return u;
//         return parent[u]=findPar(parent[u]);
//     }
//     void unionn(int u,int v){
//         u=findPar(u);
//         v=findPar(v);
//         if(rank[u]>rank[v]){
//             parent[v]=u;
//         }
//         else if(rank[u]<rank[v]){
//             parent[u]=v;
//         }
//         else{
//             parent[u]=v;
//             rank[v]++;
//         }
//     }
//     int minScore(int n, vector<vector<int>>& roads) {
//         // vector<pair<int,int>> adj[n+1];
//         // for(auto it:roads){
//         //     int a=it[0],b=it[1],wt=it[2];
//         //     adj[a].push_back({b,wt});
//         //     adj[b].push_back({a,wt});
//         // }
//         sort(roads.begin(),roads.end(),[&](vector<int> &a,vector<int>&b){
//             return a[2]<b[2];
//         });
//         parent.resize(n);//node-1 =>put everywhere
//         rank.resize(n);
//         for(int i=0;i<n;i++){
//             parent[i]=i;
//         }
//         int res=INT_MAX;
//         for(auto it:roads){
//             int a=it[0],b=it[1],wt=it[2];
//             if(findPar(a-1)!=findPar(b-1)){
//                 res=min(res,wt);
//                 unionn(a-1,b-1);
//             }
//         }
//         return res;
//     }
// };
class Solution {
public:

 int minScore(int n, vector<vector<int>>& roads) {
        vector<int> dis(n+1,INT_MAX) ;
        vector<pair<int,int>> adj[n+1];
        for(auto it:roads) {
          int u = it[0];
          int v = it[1];
          int wt = it[2];
          adj[u].push_back({v,wt});
          adj[v].push_back({u,wt});
        }
        queue<pair<int,int>> q;
        dis[1] = 0;
        q.push({1,INT_MAX});
        int res = INT_MAX;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
              auto front = q.front();
              q.pop();
              int node = front.first;
              int curScore = front.second;
              for(auto it : adj[node]) {
                int newNode = it.first;
                int newDist = it.second;
                newDist = min(newDist,curScore);
                if(newDist < dis[newNode]) {
                  dis[newNode] = newDist;
                  res = min(res,newDist);
                    q.push({newNode,newDist});
                }
              }
            }
        }
       return res;
    }
    //niraj

};





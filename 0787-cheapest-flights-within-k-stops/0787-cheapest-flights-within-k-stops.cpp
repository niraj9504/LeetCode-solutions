class Solution {
public:
    using pi=pair<int,int>;
    using vi=vector<int>;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pi> adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<vi,vector<vi>,greater<vi>> pq;
        vector<int> dist(n,INT_MAX);//stops
        pq.push({0,src,0});//
        while(!pq.empty()){
            auto it=pq.top();pq.pop();
            int cost=it[0];
            int node=it[1];
            int stop=it[2];
            if(node==dst){
                return cost;
            }
            if(dist[node]<stop)continue;//**select best(min) k
            dist[node]=stop;
            if(stop>k)continue;
            for(auto it:adj[node]){
                pq.push({cost+it.second,it.first,stop+1});
            }
        }
        return -1;
    }
};
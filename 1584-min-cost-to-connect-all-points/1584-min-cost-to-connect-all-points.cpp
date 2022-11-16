class Solution {
public:
    int parent[1001];
	int rank[1001];
	int findParent(int u){
	    if(parent[u]==u)return u;
	    return parent[u]=findParent(parent[u]);
	}
	void unionn(int u,int v){
	    u=findParent(u);
	    v=findParent(v);
	    if(rank[u]>rank[v]){
	        parent[v]=u;
	    }
	    else if(rank[u]<rank[v]){
	        parent[u]=v;
	    }
	    else{
	        parent[u]=v;
	        rank[v]++;
	    }
	}
    using pi=pair<int,pair<int,int>>;
    int minCostConnectPoints(vector<vector<int>>& p) {
        int n=p.size();
        vector<pair<int,int>> adj[n];
        for(int i=0;i<n;i++){
            int x=p[i][0],y=p[i][1];
            for(int j=i+1;j<n;j++){
                int x1=p[j][0],y1=p[j][1];
                int d=abs(x-x1)+abs(y-y1);
                adj[i].push_back({j,d});
                adj[j].push_back({i,d});
            }
        }
        for(int i=0;i<1001;i++){
            parent[i]=i;
            rank[i]=0;
        }
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        for(int i=0;i<n;i++){
            for(auto [v,w]:adj[i]){
                pq.push({w,{i,v}});//wt,u,v
            }
        }
        int cost=0;
        while(!pq.empty()){
            auto it=pq.top();pq.pop();
            int w=it.first,u=it.second.first,v=it.second.second;
            if(findParent(u)!=findParent(v)){
                cost+=w;
                unionn(u,v);
            }
        }
        return cost;
    }
};
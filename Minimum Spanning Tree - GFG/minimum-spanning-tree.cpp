//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
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
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //Kruskal's DSU
        for(int i=0;i<1001;i++){
            parent[i]=i;
            rank[i]=0;
        }
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                pq.push({it[1],{i,it[0]}});//wt,u,v
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

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
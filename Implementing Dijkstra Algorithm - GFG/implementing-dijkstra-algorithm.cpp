//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    using pi=pair<int,int>;
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pi,vector<pi>,greater<pi>> pq;//dist node
        pq.push({0,S});
        vector<int> dis(V,INT_MAX);
        dis[S]=0;
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            for(auto it:adj[p.second]){
                if(dis[it[0]]>dis[p.second]+it[1]){
                    dis[it[0]]=dis[p.second]+it[1];
                    pq.push({dis[it[0]],it[0]});
                }
            }
        }
        return dis;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends
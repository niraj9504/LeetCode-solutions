//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    void dfs(vector<int> adj[],int src,int par,vector<int> val[]){
        for(auto it:adj[src]){
            if(it!=par){
                dfs(adj,it,src,val);
            }
        }
        for(auto it:adj[src]){
            if(it!=par){
                val[src][0]+=val[it][1];
                val[src][1]+=min(val[it][0],val[it][1]);
            }
        }
    }
    int countVertex(int n, vector<vector<int>>edges){
        vector<int> adj[n+1];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        // vector<int> indegree(n+1);
        // for(int i=1;i<=n;i++){
        //     for(auto it:adj[i]){
        //         indegree[it]++;
        //     }
        // }
        // vector<int> vis(n+1);
        // priority_queue<pi,vector<pi>,greater<pi>> pq;
        // int cnt=0;
        // for(int i=1;i<=n;i++){
        //     pq.push({indegree[i],i});
        // }
        // while(!pq.empty()){
        //     int node=pq.top();
        //     pq.pop();
        //     for(auto it:adj[node]){
                
        //     }
        // }
        
        vector<int> val[n+1];
        for(int i=1;i<=n;i++){
            val[i]={0,1};
        }
        dfs(adj,1,1,val);
        return min(val[1][0],val[1][1]);
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
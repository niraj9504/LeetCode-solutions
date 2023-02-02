//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  vector<vector<int>> adj;
  vector<int> vis,par,tmp;
  using ll=long long;
  ll dfs(int node,int p=-1){
      vis[node]=1;
      par[node]=p;
      tmp.push_back(node);
      for(auto it:adj[node]){
          if(!vis[it]){
              ll z=dfs(it,node);
              if(z!=-1)return z;
          }
          else if(vis[it]==1){
              ll sum=it;
              while(node!=it){
                  sum+=node;
                  node=par[node];
              }
              if(node==it){
                  return sum;
              }
              return -1;
          }
      }
      return -1;
  }
  long long largestSumCycle(int n, vector<int> e)
  {
    adj=vector<vector<int>>(n);
    vis=vector<int> (n);
    par=vector<int> (n);
    for(int i=0;i<n;i++){
        if(e[i]!=-1){
            adj[i].push_back(e[i]);
        }
    }
    long long ans=-1;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            ans=max(ans,dfs(i));
            for(auto j:tmp){
                vis[j]=2;
            }
            tmp.clear();
        }
    }
    return ans;
  }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends
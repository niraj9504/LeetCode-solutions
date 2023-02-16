//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    int cnt=0,m;
    unordered_map<int,bool> map;
    vector<int> par;
    bool dfs(int node,vector<int> &vis,vector<int> &arr,int &x,int parent){
        vis[node]=1;
        par[node]=parent;
        if(node+arr[node]>=m || node+arr[node]<0){
            return true;
        }
        else if(vis[(node+arr[node])]==1 && map.find(par[node+arr[node]])!=map.end() && map[par[node+arr[node]]]){
            return true;
        }
        else if(vis[(node+arr[node])]==1){
            return false;
        }
        x++;
        return dfs(node+arr[node],vis,arr,x,parent);
    }
    int goodStones(int n,vector<int> &arr){
        m=n;
        vector<int> vis(n);
        par.resize(n);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int x=1;
                if(dfs(i,vis,arr,x,i)){
                    cnt+=x;
                    map[i]=true;
                    // cout<<x<<" "<<i<<endl;
                }
                else{
                    map[i]=false;
                }
            }
        }
        return cnt;
    }  
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends
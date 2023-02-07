//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      //Code Here
      long long x=n*n;
      int rr=0,cc=0;//marked rows and columns
      vector<long long int> ans;
    //   unordered_set<int> mapr,mapc;
    vector<bool> mapr(n+1,0),mapc(n+1,0);
      for(auto it:arr){
          int r=it[0],c=it[1];
          if(!mapr[r]){
              x-=(n-cc);
              rr++;
              mapr[r]=true;
          }
          if(!mapc[c]){
              x-=(n-rr);
              cc++;
              mapc[c]=true;
          }
          ans.push_back(x);
      }
      return ans;
  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends
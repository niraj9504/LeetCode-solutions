//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    #define ll long long
    long long bestNode(int n, vector<int> &a, vector<int> &p) {
        //root(1)/any node to leaf => +,-,+,-,...
        //leaf to root => each time sum*=-1
        if(n==1)return a[0];
        unordered_set<int> map(p.begin()+1,p.end());
        vector<int> leaf;
        for(int i=1;i<=n;i++){
            if(map.find(i)==map.end())leaf.push_back(i);
        }
        ll ans=INT_MIN;
        for(auto it:leaf){
            ll sum=0;
            while(it>=1){
                sum*=-1;
                sum+=a[it-1];
                ans=max(ans,sum);
                it=p[it-1];
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        long long res = obj.bestNode(N, A, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
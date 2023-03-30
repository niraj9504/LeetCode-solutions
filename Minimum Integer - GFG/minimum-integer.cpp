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
    int minimumInteger(int n, vector<int> &a) {
        // code here
        // sort(a.begin(),a.end());
        long long sum=accumulate(a.begin(),a.end(),(long long)0);
        // int y=sum/n;
        // cout<<y<<endl;
        // int x=lower_bound(a.begin(),a.end(),y)-a.begin();
        long long x=1e9;
        for(int i=0;i<n;i++){
            if((n*1LL*a[i])>=sum && x>a[i])x=a[i];
        }
        return x;
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
        
        Solution obj;
        int res = obj.minimumInteger(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
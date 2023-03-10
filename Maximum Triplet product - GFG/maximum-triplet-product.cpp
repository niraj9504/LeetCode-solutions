//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
    	#define ll long long
    	sort(arr,arr+n);
    	ll m1=arr[n-1],m2=arr[n-2],m3=arr[n-3];
    	ll n1=arr[0],n2=arr[1];
    	ll ans=m1*m2*m3;
    	ans=max(ans,max((m1*m2*m3),(m1*n1*n2)));
    	return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends
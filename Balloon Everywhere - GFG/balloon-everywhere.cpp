//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        int b=0,a=0,l=0,o=0,n=0;
        for(auto it:s){
            if(it=='b')b++;
            else if(it=='a')a++;
            else if(it=='l')l++;
            else if(it=='o')o++;
            else if(it=='n')n++;
        }
        l/=2;
        o/=2;
        return min(b,min(a,min(l,min(o,n))));
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends
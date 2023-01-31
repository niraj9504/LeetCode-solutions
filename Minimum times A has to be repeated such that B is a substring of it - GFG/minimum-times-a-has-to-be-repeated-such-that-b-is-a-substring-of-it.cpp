//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool isSubString(string s,string s2){
        int i=0,n=s2.size();
        // while(s[i]!=s2[0])i++;
        // cout<<s.substr(i)<<endl;
        // return s.substr(i)==s2;
        string temp;
        while(i<s.size()){
            if(s[i]!=s2[0])i++;
            else{
                if(s.substr(i).size()<n)return false;
                temp=s.substr(i,n);
                if(temp==s2)return true;
                i++;
            }
        }
        return false;
    }
    int minRepeats(string s1, string s2) {
        // code here
        string s=s1;
        int cnt=1;
        while(s.size()<s2.size()){
            s+=s1;
            cnt++;
        }
        if(isSubString(s,s2))return cnt;
        if(isSubString(s+s1,s2))return cnt+1;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends
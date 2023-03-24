//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string s) {
        int n=s.size();
        int freq[26]={0};
        for(auto it:s){
            freq[it-'a']++;
        }
        int l=0,r=n-1,f=0;
        while(l<=r){
            if(f==0){
                if(freq[s[l]-'a']==1){
                    l++;
                }
                else{
                    freq[s[l]-'a']--;
                    s[l]='#';
                    l++;
                    f^=1;
                }
            }
            else{
                if(freq[s[r]-'a']==1){
                    r--;
                }
                else{
                    freq[s[r]-'a']--;
                    s[r]='#';
                    r--;
                    f^=1;
                }
            }
        }
        string ans="";
        for(auto it:s){
            if(it!='#'){
                ans.push_back(it);
            }
        }
        if(f)reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends
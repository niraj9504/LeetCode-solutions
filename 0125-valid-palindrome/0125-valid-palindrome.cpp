class Solution {
public:
    bool solve(string &s,int i,int j){
        while(i<j){
            if(s[i++]!=s[j--])return false;
        }
        return true;
    }
    bool isPalindrome(string s) {
        transform(s.begin(),s.end(),s.begin(),:: tolower);
        int n=s.size();
        string x="";
        for(int i=0;i<n;i++){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
                x+=s[i];
            }
        }
        // cout<<x<<" ";
        
        return solve(x,0,x.size()-1);
    }
};
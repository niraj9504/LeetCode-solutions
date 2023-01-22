class Solution {
public:
    vector<vector<string>> ans;
    int n;
    bool isPal(int i,int j,string &s){
        while(i<j){
            if(s[i++]!=s[j--])return false;
        }
        return true;
    }
    void solve(int i,string s,vector<string> &temp){
        if(i>=n){
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<n;j++){
            if(isPal(i,j,s)){
                temp.push_back(s.substr(i,j-i+1));
                solve(j+1,s,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n=s.size();
        vector<string> temp;
        solve(0,s,temp);
        return ans;
    }
};
class Solution {
public:
    unordered_map<string,int> map,dp;
    bool solve(string s,unordered_map<string,int> &map){
        if(map.find(s)!=map.end())return true;
        if(dp.find(s)!=dp.end())return dp[s];
        for(int i=1;i<s.size();i++){
            string x=s.substr(0,i);
            if(map.find(x)!=map.end() && solve(s.substr(i),map))return dp[s]=true;
        }
        return dp[s]=false;
    }
    bool wordBreak(string s, vector<string>& w) {
        for(auto it:w)map[it]++;
        return solve(s,map);
    }
};
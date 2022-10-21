class Solution {
public:
    unordered_map<string,int> map;
    int solve(int cnt,int s,int e,vector<int> &cuts){
        if(cnt==cuts.size())return 0;
        int len=e-s;
        string u=to_string(s)+"$"+to_string(e);;
        if(map.find(u)!=map.end())return map[u];
        int x=INT_MAX;
        for(auto it:cuts){
            if(it>s && it<e){
                x=min(x,(solve(cnt+1,s,it,cuts)+solve(cnt+1,it,e,cuts)+len));
            }
        }
        return map[u]=x==INT_MAX?0:x;
    }
    int minCost(int l, vector<int>& cuts) {
        int n=cuts.size();
        sort(cuts.begin(),cuts.end());
        return solve(0,0,l,cuts);
    }
};
class comp{
    public:
        bool operator()(const pair<int,string> &a,const pair<int,string> &b){
            if(a.first!=b.first)return a.first>b.first;
            return a.second<b.second;
        }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string,int> mp;
        for(auto it:words){
            mp[it]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,comp> minH;
        for(auto it:mp){
            minH.push({it.second,it.first});
            if(minH.size()>k)minH.pop();
        }
        while(!minH.empty()){
            //ans.insert(ans.begin(), minH.top().second);//**** otherwise use reverse
            ans.push_back(minH.top().second);
            minH.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
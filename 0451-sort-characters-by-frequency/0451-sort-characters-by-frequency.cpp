class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> map;
        string ans="";
        for(auto it:s){
            map[it]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto [ch,freq]:map){
            pq.push({freq,ch});
        }
        string temp="";
        while(!pq.empty()){
            auto [freq,ch]=pq.top();
            pq.pop();
            ans.append(freq,ch);
        }
        return ans;
    }
};
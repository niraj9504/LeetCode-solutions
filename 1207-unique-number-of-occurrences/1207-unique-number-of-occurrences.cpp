class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>map;
        unordered_set<int> freq;
        for(auto it:arr)map[it]++;
        for(auto [a,b]:map){
            if(freq.find(b)!=freq.end()){
                return false;
            }
            freq.insert(b);
        }
        return true;
    }
};
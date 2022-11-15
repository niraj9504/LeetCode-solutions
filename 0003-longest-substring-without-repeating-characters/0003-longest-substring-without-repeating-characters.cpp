class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,n=s.size();
        int ans=0;
        unordered_map<char,int> map;//val idx
        for(int j=0;j<n;j++){
            if(map.find(s[j])!=map.end()){
                i=max(i,map[s[j]]+1);
            }
            map[s[j]]=j;
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};
class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> map;
        for(int i=0;i<s.size();i++){
            if(map.find(s[i])!=map.end()){
                return s[i];
            }
            map.insert(s[i]);
        }
        return 'a';
    }
};
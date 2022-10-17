class Solution {
public:
    bool checkIfPangram(string s) {
        int p[26]={0};
        for(auto it:s){
            p[it-'a']++;
        }
        for(auto it:p){
            if(it==0)return false;
        }
        return true;
    }
};
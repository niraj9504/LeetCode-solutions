class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int l=0;
        unordered_map<string,int> map;
        string t;
        int pair=0;
        for(auto w:words){
            if(w[0]==w[1]){
                if(map[w]>0){
                    l+=4;
                    pair--;
                    map[w]--;
                }
                else{
                    pair++;
                    map[w]++;
                }
            }
            else{
                t=w;
                reverse(t.begin(),t.end());
                if(map[t]>0){
                    l+=4;
                    map[t]--;
                }
                else{
                    map[w]++;
                }
            }
        }
        if(pair>0)l+=2;
        return l;
    }
};
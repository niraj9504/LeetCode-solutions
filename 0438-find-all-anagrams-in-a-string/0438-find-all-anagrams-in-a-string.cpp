class Solution {
public:
    bool isEqual(vector<int> &a,vector<int> &b){
        for(int i=0;i<26;i++){
            if(a[i]!=b[i])return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n=s.size(),m=p.size();
        if(m>n)return {};
        vector<int> freq1(26,0),freq2(26,0);
        for(auto it:p){
            freq1[it-'a']++;
        }
        
        int i=0,j=0;
        vector<int> ans;
        while(j<n){
            freq2[s[j]-'a']++;
            
            if(j-i+1==m){
                if(isEqual(freq1,freq2)){
                    ans.push_back(i);
                }
            }
            
            if(j-i+1<m)j++;
            else{
                freq2[s[i]-'a']--;
                i++;
                j++;
            }
        }
        return ans;
    }
};
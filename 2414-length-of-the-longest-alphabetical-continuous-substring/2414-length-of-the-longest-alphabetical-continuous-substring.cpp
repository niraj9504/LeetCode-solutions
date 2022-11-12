class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(i==0 || s[i]-'a'!=s[i-1]-'a'+1){
                int curr=1;
                while(i+1<n && s[i]-'a'+1==s[i+1]-'a'){
                    curr++;
                    i++;
                }
                ans=max(ans,curr);
            }
        }
        return ans;
    }
};
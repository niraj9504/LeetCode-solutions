class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& s) {
        int n=s.size();
        sort(s.begin(),s.end());
        int ans=0;
        ans=max(s[0]-bottom,top-s[n-1]);
        if(ans>(s[n-1]-s[0]-2) || n==1)return ans;
        for(int i=0;i<n-1;i++){
            ans=max(s[i+1]-s[i]-1,ans);
        }
        return ans;
    }
};
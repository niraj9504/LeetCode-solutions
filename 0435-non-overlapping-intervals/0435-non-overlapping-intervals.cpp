class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& x) {
        sort(x.begin(),x.end(),comp);
        int ans=0,n=x.size();
        int prevE=x[0][1];
        for(int i=1;i<n;i++){
            int start=x[i][0], end=x[i][1];
            if(prevE>start)ans++;
            else{
                prevE=end;
            }
        }
        return ans;
    }
};
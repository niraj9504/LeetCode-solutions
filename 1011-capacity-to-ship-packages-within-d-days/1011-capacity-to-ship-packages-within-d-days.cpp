class Solution {
public:
    bool check(vector<int> &w,int d,int mid){
        int cnt=0;
        int j=0,sum=0;
        while(j<w.size()){
            sum+=w[j];
            if(sum>mid){
                cnt++;
                sum=w[j];
            }
            j++;
        }
        cnt++;
        if(cnt<=d)return true;
        return false;
    }
    int shipWithinDays(vector<int>& w, int d) {
        int n=w.size();
        // sort(w.begin(),w.end());
        int low=*max_element(w.begin(),w.end()) ,high=accumulate(w.begin(),w.end(),0);
        int ans=high;
        while(low<=high){
            int mid=(low+(high-low)/2);
            if(check(w,d,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
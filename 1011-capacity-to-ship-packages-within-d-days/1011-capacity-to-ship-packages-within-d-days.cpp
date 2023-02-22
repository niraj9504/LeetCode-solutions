class Solution {
public:
    bool ifPoss(vector<int> &w,int d,int cap){
        int cnt=1;
        int sum=0;
        for(int i=0;i<w.size();i++){
            if(w[i]>cap)return false;
            sum+=w[i];
            if(sum>cap){
                sum=w[i];
                cnt++;
            }
        }
        return cnt<=d;
    }
    int shipWithinDays(vector<int>& w, int d) {
        int sum=accumulate(w.begin(),w.end(),0);
        int low=sum/d;
        int high=sum;
        while(low<high){
            int mid=(low+(high-low)/2);
            if(ifPoss(w,d,mid)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
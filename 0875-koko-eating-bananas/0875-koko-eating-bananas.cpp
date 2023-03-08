class Solution {
public:
    bool isPoss(int m,vector<int> &p,int h){
        int cnt=0;
        for(auto it:p){
            if(it%m==0)
                cnt+=(it/m);
            else cnt+=((it/m)+1);
            
            if(cnt>h)return false;
        }
        return cnt<=h;
    }
    int minEatingSpeed(vector<int>& p, int h) {
        int n=p.size();
        int high=*max_element(p.begin(),p.end());
        if(h==n)return high;
        int low=1;
        // int mid=low;
        while(low<high){
            int mid=(high+low)/2;
            if(isPoss(mid,p,h)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
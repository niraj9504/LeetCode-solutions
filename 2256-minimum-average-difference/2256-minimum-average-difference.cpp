class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        long long end=accumulate(nums.begin(),nums.end(),(long long)0);
        long long start=0;
        long long avg=0,ans=0,prev=INT_MAX;
        for(int i=0;i<n;i++){
            start+=nums[i];
            end-=nums[i];
            if(i!=n-1){
                avg=abs(start/(i+1)-end/(n-i-1));
            }
            else{
                avg=abs(start/(i+1)-end/1);
            }
            if(avg<prev){
                ans=i;
                prev=avg;
            }
        }
        return ans;
    }
};
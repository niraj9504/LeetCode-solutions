class Solution {
public:
    int merge(vector<int> &nums,int s,int m,int e){
        int inv=0;
        int i=s,j=m+1;
        while(i<=m && j<=e){
            if(nums[i]<=2LL*nums[j]){
                i++;
            }
            else{
                inv+=(m-i+1);
                j++;
            }
        }
        i=s,j=m+1;
        vector<int> t;
        while(i<=m && j<=e){
            if(nums[i]<=nums[j]){
                t.push_back(nums[i++]);
            }
            else{
                t.push_back(nums[j++]);
            }
        }
        while(i<=m)t.push_back(nums[i++]);
        while(j<=e)t.push_back(nums[j++]);
        for(int i=s;i<=e;i++){
            nums[i]=t[i-s];
        }
        return inv;
    }
    int mergesort(vector<int> &nums,int s,int e){
        if(s>=e)return 0;
        int inv=0;
            int mid=(s+e)/2;
            inv+=mergesort(nums,s,mid);
            inv+=mergesort(nums,mid+1,e);
            inv+=merge(nums,s,mid,e);
        return inv;
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return mergesort(nums,0,n-1);
    }
};
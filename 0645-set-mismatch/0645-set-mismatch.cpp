class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // int *m=max_element(nums.begin(),nums.end());
        int n=nums.size(),a=-1,b=-1;
        vector<int> v(n+1);
        for(int i=0;i<n;i++){
            v[nums[i]]++;
        }
        for(int i=1;i<=n;i++){
            if(v[i]>1)a=i;
            if(v[i]==0)b=i;
            if(a>0 && b>0)return {a,b};
        }
        return {a,b};
    }
};
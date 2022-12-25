class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& q) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        //for(auto it:nums)cout<<it<<" ";
        int m=q.size();//cout<<endl;
        for(int i=0;i<m;i++){
            int idx=lower_bound(nums.begin(),nums.end(),q[i])-nums.begin();
            // cout<<idx<<" ";
            if(idx==n)q[i]=n;
            else
                q[i]=(nums[idx]==q[i])?idx+1:idx;
        }
        return q;
    }
};
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1=-1,n2=-1,cn1=0,cn2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==n1)cn1++;
            else if(nums[i]==n2)cn2++;
            else if(cn1==0){
                n1=nums[i];
                cn1=1;
            }
            else if(cn2==0){
                n2=nums[i];
                cn2=1;
            }
            else{
                cn1--;
                cn2--;
            }
        }
        cn1=cn2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==n1)cn1++;
            else if(nums[i]==n2)cn2++;
        }
        vector<int> ans;
        if(cn1>nums.size()/3)ans.push_back(n1);
        if(cn2>nums.size()/3)ans.push_back(n2);
        return ans;
    }
};
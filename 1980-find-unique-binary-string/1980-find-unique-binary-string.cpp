class Solution {
public:
    string ans;
    void solve(int i,int n,unordered_set<string> &map,string curr,bool flag){
        if(flag)return;
        if(i==n){
            if(map.find(curr)==map.end()){
                flag=true;
                ans=curr;
            }
            return;
        }
        solve(i+1,n,map,curr+'0',flag);
        solve(i+1,n,map,curr+'1',flag);
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums[0].size();
        unordered_set<string> map(nums.begin(),nums.end());
        solve(0,n,map,"",false);
        return ans;
    }
};
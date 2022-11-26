class Solution {
public:
    class pr{
        public:
        int s;
        int e;
        int p;
        pr(int s,int e,int p){
            this->s=s;
            this->e=e;
            this->p=p;
        }
    };
    int n;
    // unordered_map<string,int> map;
    // int solve(int i,vector<pr> &nums,int end){
    //     if(i==n)return 0;
    //     int take=0;
    //     string s=to_string(i)+"+"+to_string(end);
    //     if(map.find(s)!=map.end())return map[s];
    //     if(end==0 || nums[i].s>=end){
    //         take=solve(i+1,nums,nums[i].e)+nums[i].p;
    //     }
    //     int not_take=solve(i+1,nums,end);
    //     return map[s]=max(take,not_take);
    // }
    int jobScheduling(vector<int>& st, vector<int>& en, vector<int>& pt) {
        n=st.size();
        vector<pr> nums;
        for(int i=0;i<n;i++){
            pr *temp=new pr(st[i],en[i],pt[i]);
            nums.push_back(*temp);
        }
        sort(nums.begin(),nums.end(),[&](const pr &a,const pr&b){
            return a.e<b.e;
        });
        map<int,int> map;
        map.insert({0,0});
        for(auto it:nums){
            int curr_pr=it.p;
            auto x=prev(map.upper_bound(it.s));
            if(x!=map.end()){
                curr_pr+=x->second;
            }
            if(curr_pr>map.rbegin()->second)
                map[it.e]=curr_pr;
        }
        return map.rbegin()->second;
    }
};
class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        // __builtin_popcount();
        // bits(num1 OR num2) + bits(num1 AND num2) = bits(num1) + bits(num2)
        //see solutions for best explanation
        long long cnt=0;
        unordered_set<int> temp(nums.begin(),nums.end());//distinct
        vector<int> bcnt(30,0);
        for(auto it:temp){
            bcnt[__builtin_popcount(it)]++;//set bits of a number, count
        }
        for(int i=0;i<30;i++){
            for(int j=0;j<30;j++){
                if(i+j>=k){
                    cnt+=(bcnt[i]*bcnt[j]);
                }
            }
        }
        return cnt;
    }
};
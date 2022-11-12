class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans=0;
        long long a=total/cost1,b=total/cost2;
        for(int i=0;i<=b;i++){
            int paisa=total-(i*cost2);
            ans+=(long long)((paisa/cost1)+1);
        }
        // ans+=(long long)(a*b);
        return ans;
    }
};
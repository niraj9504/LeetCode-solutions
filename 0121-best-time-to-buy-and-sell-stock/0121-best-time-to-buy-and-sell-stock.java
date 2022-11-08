class Solution {
    public int maxProfit(int[] prices) {
        Integer buy=100000,profit=0,n=prices.length;
        if(n==1)return 0;
        for(int i=0;i<n;i++){
            profit=Math.max(profit,prices[i]-buy);
            buy=Math.min(buy,prices[i]);
        }
        return profit;
    }
}
class StockSpanner {
    Stack<int[]> st=new Stack();
    public StockSpanner() {
        
    }
    
    public int next(int price) {
        int cnt=1;
        while(!st.isEmpty() && st.peek()[0]<=price){
            cnt+=st.pop()[1];
        }
        st.push(new int[]{price,cnt});
        return cnt;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */
class Solution {
public:
    vector<int> finalPrices(vector<int>& p) {
        //next smaller element
        int n=p.size();
        vector<int> nse(n);
        for(int i=0;i<n;i++)nse[i]=p[i]+1;
        stack<int> st;//index of prev
        for(int i=0;i<n;i++){
            while(!st.empty() && nse[st.top()]>p[i]){
                nse[st.top()]=p[i];
                st.pop();
            }
            st.push(i);
        }
        // for(auto it:nse)cout<<it<<" ";
        for(int i=0;i<n;i++){
            if(p[i]>=nse[i]){
                p[i]-=nse[i];
            }
        }
        return p;
    }
};
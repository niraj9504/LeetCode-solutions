class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        //next smaller element's index and prev smaller element's index
        int n=arr.size();
        vector<int> nse(n),pse(n);
        for(int i=0;i<n;i++){
            nse[i]=n-i-1;
            pse[i]=i;
        }
        stack<int> s1,s2;
        for(int i=0;i<n;i++){
            while(!s1.empty() && arr[s1.top()]>arr[i]){
                nse[s1.top()]=i-s1.top()-1;
                s1.pop();
            }
            s1.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!s2.empty() && arr[s2.top()]>=arr[i]){
                pse[s2.top()]=s2.top()-i-1;
                s2.pop();
            }
            s2.push(i);
        }
        long long sum=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            sum=(sum + ((long long)arr[i]*(nse[i]+1)*(pse[i]+1)))%mod;
            sum=(sum%mod);
        }
        return sum;
    }
};
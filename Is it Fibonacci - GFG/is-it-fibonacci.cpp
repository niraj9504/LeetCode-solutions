//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int n, int k, vector<long long> nums) {
        if(k==1)return nums[0];
        long long sum=accumulate(nums.begin(),nums.end(),0);
        int left=0,x=n-k;
        if(x<=0){
            return nums[n-1];
        }
        nums.push_back(sum);
        while(x>1){
            sum+=sum;
            sum-=nums[left++];
            nums.push_back(sum);
            // cout<<sum<<endl;
            x--;
        }
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        vector<int> s(26),b(26);
        // priority_queue<int,vector<int>,greater<int>> s,b;
        for(int i=0;i<n;i++){
            if(str[i]-'a'>=0){
                s[str[i]-'a']++;
                // s.push(str[i]-'a');
            }
            else{
                b[str[i]-'A']++;
                // b.push(str[i]-'A');
            }
        }
        int a=0,A=0;//index
        for(int i=0;i<n;i++){
            if(str[i]-'a'>=0){
                // str[i]=s.top()+'a';
                // s.pop();
                while(s[a]<=0)a++;
                str[i]=a+'a';
                s[a]--;
            }
            else{
                // str[i]=b.top()+'A';
                // b.pop();
                while(b[A]<=0)A++;
                str[i]=A+'A';
                b[A]--;
            }
        }
        return str;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends
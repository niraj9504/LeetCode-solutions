class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        int n=s.size();
        vector<vector<string>> ans;
        if(n==0)return ans;
        vector<string> temp=s;
        for(int i=0;i<n;i++){
            string x=temp[i];
            sort(x.begin(),x.end());
            temp[i]=x;
        }
        multimap<string,int> map;
        for(int i=0;i<n;i++){
            map.insert({temp[i],i});
        }
        vector<string> v;
        string prev="";
        for(auto it:map){
            // cout<<it.first<<" "<<it.second<<endl;
            if(v.size()==0 || prev==it.first){
                v.push_back(s[it.second]);
                prev=it.first;
            }   
            else{
                ans.push_back(v);
                v.clear();
                v.push_back(s[it.second]);
                prev=it.first;
            }
        }
        ans.push_back(v);
        return ans;
    }
};
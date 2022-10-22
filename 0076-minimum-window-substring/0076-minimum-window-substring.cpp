class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size(),n=t.size();
        if(n>m || m==0 || n==0)return "";
        unordered_map<char,int> map,temp;
        for(auto it:t)map[it]++;
        int req=map.size(),formed=0;
        int i=0,j=0;
        int ans[]={-1,0,0};
        while(j<m){
            temp[s[j]]++;
            if(map.find(s[j])!=map.end() && temp[s[j]]==map[s[j]])formed++;
            while(i<=j && req==formed){
                if(ans[0]==-1 || j-i+1<ans[0]){
                    ans[0]=j-i+1;
                    ans[1]=i;
                    ans[2]=j;
                }
                temp[s[i]]--;
                if(map.find(s[i])!=map.end() && map[s[i]]>temp[s[i]])formed--;
                i++;
            }
            j++;
        }
        return ans[0]==-1?"":s.substr(ans[1],ans[0]);
    }
};
class Solution {
public:
    int minMutation(string s, string e, vector<string>& b) {
        unordered_set<string> map(b.begin(),b.end());
        if(map.find(e)==map.end())return -1;
        queue<string> q;
        q.push(s);
        int cnt=0;
        string x;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto it=q.front();
                q.pop();
                if(it==e)return cnt;
                map.erase(it);
                for(int i=0;i<8;i++){
                    x=it;
                    x[i]='A';
                    if(map.find(x)!=map.end())q.push(x);
                    x[i]='C';
                    if(map.find(x)!=map.end())q.push(x);
                    x[i]='G';
                    if(map.find(x)!=map.end())q.push(x);
                    x[i]='T';
                    if(map.find(x)!=map.end())q.push(x);
                }
            }
            cnt++;
        }
        return -1;
    }
};
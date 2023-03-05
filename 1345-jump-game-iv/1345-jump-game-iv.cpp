class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>> map;
        int n=arr.size();
        for(int i=0;i<n;i++){
            map[arr[i]].push_back(i);
        }
        vector<int> vis(n,0);
        queue<int> q;
        q.push(0);
        vis[0]=1;
        int step=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int node=q.front();
                q.pop();
                if(node==n-1)return step;
                auto &next=map[arr[node]];
                next.push_back(node+1);
                next.push_back(node-1);
                
                for(auto i:next){
                    if(i>=0 && i<n && !vis[i]){
                        vis[i]=1;
                        q.push(i);
                    }
                }
                next.clear();
            }
            step++;
        }
        return step;
    }
};
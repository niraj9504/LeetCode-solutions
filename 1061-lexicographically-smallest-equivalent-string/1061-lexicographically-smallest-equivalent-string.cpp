class Solution {
public:
    vector<int> rank;
    vector<int> parent;
    int findPar(int node){
        if(parent[node]==node)return node;
        return parent[node]=findPar(parent[node]);
    }
    void unionn(int u,int v){
        u=findPar(u);
        v=findPar(v);
        if(rank[u]>rank[v]){
            parent[u]=parent[v];
        }
        else{
            parent[v]=parent[u];
        }
    }
    string smallestEquivalentString(string s1, string s2, string s) {
        int n=s1.size(),m=s.size();
        rank.resize(26);
        parent.resize(26);
        for(int i=0;i<26;i++){
            parent[i]=i;
            rank[i]=i;
        }
        for(int i=0;i<n;i++){
            unionn(s1[i]-'a',s2[i]-'a');
        }
        for(int i=0;i<m;i++){
            s[i]=('a'+findPar(s[i]-'a'));
            // cout<<findPar(s[i]-'a')<<" ";
        }
        return s;
    }
};
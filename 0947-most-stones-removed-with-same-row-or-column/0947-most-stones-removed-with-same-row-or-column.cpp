class Solution {
public:
    int parent[20005];
    int rank[20005];
    int findParent(int a){
        if(parent[a]==a){
            return a;
        }
        return parent[a]=findParent(parent[a]);
    }
    void unionn(int u,int v){
        u=findParent(u);
        v=findParent(v);
        if(rank[u]>rank[v]){
            parent[v]=u;
        }
        else if(rank[u]<rank[v]){
            parent[u]=v;
        }
        else{
            parent[u]=v;
            rank[v]++;
        }
    }
    int removeStones(vector<vector<int>>& s) {
        // make matrix and analyse
        // make graph (if row or col matches => same comp.)=> find connected components => remove until one element left
        //see Riddhi dutta solution(x=x,y=10000+y) and connect them
        for(int i=0;i<20005;i++){
            parent[i]=i;
            rank[i]=0;
        }
        for(auto it:s){
            int x=it[0],y=it[1]+10000;
            unionn(x,y);
        }
        unordered_set<int> components;//gives distinct comp
        for(auto it:s){
            components.insert(findParent(it[0]));
        }
        return s.size()-components.size();
    }
};
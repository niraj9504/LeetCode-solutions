class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> map;
        int l=0,ans=0,n=fruits.size();
        for(int r=0;r<n;r++){
            map[fruits[r]]++;
            
            while(map.size()>2){
                map[fruits[l]]--;
                if(map[fruits[l]]==0){
                    map.erase(fruits[l]);
                }
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
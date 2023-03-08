class Solution {
public:
    int minEatingSpeed(vector<int>& p, int h) {
        int n=p.size();
        int r=*max_element(p.begin(),p.end());
        if(h==n)return r;
        int l=1;
        int total=0;
        while (l < r) {
            int m = (l + r) / 2, total = 0;
            for (auto it : p)
                total += (it + m - 1) / m;
            if (total > h)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
};
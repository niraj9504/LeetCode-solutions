class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.size();
        int j=n/2,cnt1=0;
        for(int i=0;i<n/2;i++){
            char x=tolower(s[i]),y=tolower(s[j]);
            if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u'){
                cnt1++;
            }
            if(y=='a' || y=='e' || y=='i' || y=='o' || y=='u'){
                cnt1--;
            }
            j++;
        }
        return cnt1==0;
    }
};
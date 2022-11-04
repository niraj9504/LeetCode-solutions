class Solution {
public:
    bool check(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U')return true;
        return false;
    }
    string reverseVowels(string x) {
        string s=x;
        int i=0,j=s.size()-1;
        while(i<j){
            if(check(s[i]) && check(s[j])){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(check(s[i])){
                j--;
            }
            else if(check(s[j])){
                i++;
            }
            else{
                i++;j--;
            }
        }
        return s;
    }
};
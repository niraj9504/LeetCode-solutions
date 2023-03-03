class Solution {
public:
    int strStr(string h, string s) {
        int n=h.size(),m=s.size();
        if(n<m)return -1;
        // int i=0;
        // stack<char> st;
        auto i=h.find(s);
        if(i!=string::npos)return i;
        return -1;
    }
};
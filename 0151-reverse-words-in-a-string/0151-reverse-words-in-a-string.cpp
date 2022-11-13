class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int n=s.size();
        string word="";
        for(int i=0;i<=n;i++){
            if(s[i]==' ' || i==n){
                if(word.size()>0)
                st.push(word);
                word="";
            }
            else{
                word+=s[i];
            }
        }
        s="";
        while(!st.empty()){
            // cout<<st.top()<<endl;
            s+=st.top();
            s+=' ';
            st.pop();
        }
        if(s.size()>0)s.pop_back();
        return s;
        
    }
};
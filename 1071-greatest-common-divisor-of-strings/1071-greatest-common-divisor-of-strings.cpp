class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        //let s2 is smaller
        string temp,curr;
        if(s2.size()>s1.size())swap(s1,s2);
        int n2=s2.size(),n1=s1.size();
        for(int i=0;i<n2;i++){
            for(int j=n2-i;j>=1;j--){
                temp=s2.substr(i,j);
                curr=temp;
                int z=n2/temp.size();
                while(z>1){
                    curr+=temp;
                    z--;
                }
                if(curr==s2){
                    z=n1/temp.size();
                }
                z-=((n2/temp.size())-1);
                while(z>1){
                    curr+=temp;
                    z--;
                }
                if(curr==s1){
                    return temp;
                }
            }
        }
        return "";
    }
};
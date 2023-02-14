class Solution {
public:
    string addBinary(string a, string b) {
        string s;
        int n=a.size(),m=b.size();
        int i=n-1,j=m-1,p=0;
        while(i>=0 && j>=0){
            int x=(a[i--]-'0')+(b[j--]-'0')+p;
            if(x==0 || x==2){
                s+='0';
            }
            else if(x==1 || x==3){
                s+='1';
            }
            if(x<2)p=0;
            else p=1;
        }
        while(i>=0){
            int x=(a[i--]-'0')+p;
            if(x==0 || x==2){
                s+='0';
            }
            else if(x==1 || x==3){
                s+='1';
            }
            if(x<2)p=0;
            else p=1;
        }
        while(j>=0){
            int x=(b[j--]-'0')+p;
            if(x==0 || x==2){
                s+='0';
            }
            else if(x==1 || x==3){
                s+='1';
            }
            if(x<2)p=0;
            else p=1;
        }
        if(p)s+='1';
        reverse(s.begin(),s.end());
        return s;
    }
};
// 111
//  11 =>    1010

class Solution {
public:
    string intToRoman(int n) {
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[]={"","M","MM","MMM"};
        
        return ths[n/1000] + hrns[(n%1000)/100] + tens[(n%100)/10] + ones[n%10];
    }
};
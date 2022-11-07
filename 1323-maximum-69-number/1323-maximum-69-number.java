class Solution {
    public int maximum69Number (int num) {
        String s=Integer.toString(num);
        char[] t=s.toCharArray();
        for(int i=0;i<t.length;i++){
            if(t[i]=='6'){
                t[i]='9';
                break;
            }
        }
        return Integer.parseInt(String.valueOf(t));
    }
}
class Solution {
    public boolean checkIfPangram(String sentence) {
        int[] temp=new int[26];
        for(int i=0;i<sentence.length();i++){
            char c=sentence.charAt(i);
            temp[c-'a']++;
        }
        for(int it:temp){
            if(it==0)return false;
        }
        return true;
    }
}
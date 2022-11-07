class Solution {
    public List<List<Integer>> generate(Integer n) {
        List<List<Integer>> ans=new ArrayList<List<Integer>>();
        for(Integer i=0;i<n;i++){
            List<Integer> row=new ArrayList<Integer>();
            for(Integer j=0;j<=i;j++){
                if(j==0 || j==i)row.add(1);
                else{
                    row.add(ans.get(i-1).get(j)+ans.get(i-1).get(j-1));
                }
            }
            ans.add(row);
        }
        return ans;
    }
}
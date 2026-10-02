class Solution {
    void generate(List<String> res,StringBuilder ans, int n1,int n2,int n){
        if(n1==n && n2==n){
            res.add(ans.toString());
            return;
        }
        ans.append('(');
        if(n1<n) generate(res,ans,n1+1,n2,n);
        ans.deleteCharAt(ans.length()-1);
        ans.append(')');
        if(n2<n && n2<n1) generate(res,ans,n1,n2+1,n);
        ans.deleteCharAt(ans.length()-1);
    }
    public List<String> generateParenthesis(int n) {
        List<String> res=new ArrayList<>();
        StringBuilder ans=new StringBuilder();
        generate(res,ans,0,0,n);
        return res;
    }
}
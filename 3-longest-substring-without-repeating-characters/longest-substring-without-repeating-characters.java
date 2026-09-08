class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashSet <Character> ans= new HashSet<>();
        int max=0;
        int l=0;
        for(int i=0;i<s.length();i++){
            char ch=s.charAt(i);
            while(ans.contains(ch)){
                ans.remove(s.charAt(l));
                l++;    
            }
                max=Math.max(max,i-l+1);
                ans.add(ch);
            
            


        }
        return max;
    }
}
class Solution {
public:
    string digitSum(string s, int k) {
        if(s.size()<=k) return s;
        string temp="";
        int sum=0;
        for(int i=0;i<s.size();i++){
            sum+=s[i]-'0';
            if((i+1)%k==0 || (i+1)==s.size()){
                temp+=to_string(sum);
                sum=0;
                }
        }
        return digitSum(temp,k);
    }
};
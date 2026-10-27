class Solution {
public:
    char value(string s,int k) {
        if (s.size()>=k) {
            return s[k-1];
        }
        string rev=s;
        reverse(rev.begin(),rev.end());

        for (int i=0;i<rev.size(); i++) {
            if (rev[i]=='0') rev[i]='1';
            else rev[i]='0';
        }
        s=s+'1'+rev;
        return value(s,k);
    }

    char findKthBit(int n, int k) {
        string s ="0";
        return value(s,k);
    }
};
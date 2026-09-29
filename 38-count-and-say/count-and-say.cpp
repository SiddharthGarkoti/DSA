class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string sh="1";
        string res="";
        while(n>1){
            for(int i=0;i<sh.size();i++){
                int count=0;
                char ch=sh[i];
                int j=i;
                while(j<sh.size() && sh[j]==ch){
                    count++;
                    j++;}
                string counts=to_string(count);
                res+=counts;
                res.push_back(ch);
                i=j-1;
            }
            sh=res;
            res="";
            n--;
        }
        return sh;
    }
};
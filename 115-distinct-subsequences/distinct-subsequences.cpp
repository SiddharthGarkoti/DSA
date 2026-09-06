class Solution {
private:
vector<vector<int>> dp;
    int check(string &s,string &t,int index,int index2){
        if(index2==t.size()) return 1;
        if(index==s.size()) return 0;
        if(dp[index][index2] != -1)
            return dp[index][index2];

        int ans=check(s,t,index+1,index2);
        if(s[index]==t[index2]){
            ans+=check(s,t,index+1,index2+1);
        }
        return dp[index][index2] = ans;
    }
public:
    int numDistinct(string s, string t) {
        dp.assign(s.size(), vector<int>(t.size(), -1));
        return check(s,t,0,0);
    }
};
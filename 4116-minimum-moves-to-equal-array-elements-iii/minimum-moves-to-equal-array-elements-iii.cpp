class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans=INT_MIN;
        for(int num:nums) ans=max(ans,num);
        int res=0;
        for(int num:nums) res+=ans-num;
        return res;
    }
};
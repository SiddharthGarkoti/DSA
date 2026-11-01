class Solution {
public:
    int minMoves(vector<int>& nums) {
       int mn=INT_MAX;
       for(int i=0;i<nums.size();i++){
        mn=min(nums[i],mn);
       }
       int res=0;
       for(int num:nums){
        res+=(num-mn);
       }
       return res;
    }
};
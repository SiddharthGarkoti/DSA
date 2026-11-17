class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if(nums.size()==1) return nums[0]%10;
        vector<int> res;
        for(int i=1;i<nums.size();i++){
            res.push_back((nums[i-1]+nums[i])%10);
        }
        return triangularSum(res);
    }
};
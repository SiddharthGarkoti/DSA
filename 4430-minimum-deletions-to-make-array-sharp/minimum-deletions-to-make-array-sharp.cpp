class Solution {
public:
    int minDeletions(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int count=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]) count++;
        }
        return count;
    }
};
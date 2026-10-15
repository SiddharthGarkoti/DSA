class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++){
            unordered_set<int>  seen;
            for(int j=i;j<nums.size();j++){
            seen.insert(nums[j]);
            res+=seen.size()*seen.size();}
        }
        return res;
    }
};
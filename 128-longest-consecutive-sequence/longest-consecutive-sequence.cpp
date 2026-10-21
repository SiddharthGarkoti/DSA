class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> seen;
        for(int i=0;i<nums.size();i++) seen.insert(nums[i]);
        if(seen.size()<=1) return seen.size();
        int count=1;
        vector<int> check;
        for(int i:seen){
            check.push_back(i);
        }
        int res=0;
        for(int i=1;i<check.size();i++){
            if(check[i]-check[i-1]==1) count++;
            else{
                res=max(res,count);
                count=1;
            }
        }
        res=max(count,res);
        return res;
    }
};
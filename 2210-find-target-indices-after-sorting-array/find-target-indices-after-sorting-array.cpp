class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int lo=0;
        int hi=nums.size()-1;
        int ans=-1;
        while(hi>=lo){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target){
                ans=mid;
                hi=mid-1;
            }
            else if(nums[mid]>target) hi=mid-1;
            else lo=mid+1;
        }
        if(ans==-1) return {};
        vector<int> res;
        for(int i=ans;i<nums.size();i++){
            if(nums[i]!=target) break;
            res.push_back(i);
        }
        return res;
    }
};
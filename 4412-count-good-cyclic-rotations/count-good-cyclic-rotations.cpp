class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        long total=0;
        long half=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        for(int i=0;i<n/2;i++){
             half+=nums[i];
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(half>total-half) ans++;
            half-=nums[i];
            half+=nums[(i+n/2)%n];
        }
        return ans;
    }
};
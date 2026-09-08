class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int l=0;
        int sum=0;
        int min=nums.length+1;;
        for(int i=0;i<nums.length;i++){
            sum=sum+nums[i];
            while(sum>=target){
               min= Math.min(min,i-l+1);
                sum=sum-nums[l];
                l++;
            }
        } // return (min==nums.length+1?0:min);
        if(min==nums.length+1){
            return 0;
        }
        else
        return min;
        
    
    }
}
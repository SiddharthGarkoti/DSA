class Solution {

    private int sumOfDigit(int n) {
      if(n==0) return 0;
        return n%10+sumOfDigit(n/10);
    }

    public int smallestIndex(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            if (i == sumOfDigit(nums[i])) {
                return i; 
            }
        }
        return -1;
    }
}

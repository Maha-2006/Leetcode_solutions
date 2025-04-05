class Solution {
    public int subsetXORSum(int[] nums) {
        int n = nums.length;
        int orr = 0;
        for(int ele: nums){
            orr |= ele;
        }
        return orr * (1<<(n-1));
    }
}
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int maxDiff = -1;
        int elements = nums[0];
        for(int j=0;j<n;j++)
        {
            if(nums[j]>elements)
            {
                maxDiff = max(maxDiff,nums[j]-elements);
            }
            else{
                 elements = nums[j];
            }
        }
     return maxDiff;
    }
};
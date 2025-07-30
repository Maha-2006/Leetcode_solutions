class Solution {
public:
    int longestSubarray(vector<int>& nums) {
         int maxVal = 0;

        // Find the maximum value in the array
        for (int num : nums) {
            maxVal = max(num, maxVal); // Use std::max or just max in C++
        }

        int maxLen = 0;
        int currLen = 0;

        // Find the length of longest subarray with maxVal
        for (int num : nums) {
            if (num == maxVal) {
                currLen++;
                maxLen = max(currLen, maxLen);
            } else {
                currLen = 0;
            }
        }

        return maxLen;
    }
};
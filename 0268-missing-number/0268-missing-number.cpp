class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int XOR_1 =0,XOR_2=0;
        int n = nums.size();
        
        for(int i=0;i<=n;i++)
        {
            XOR_1 ^= i;
        }

        for(int i=0;i<n;i++)
        {
            XOR_2 ^= nums[i];
        }
        return XOR_1 ^ XOR_2;
    }
};
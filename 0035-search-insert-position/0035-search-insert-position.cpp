class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0,high = nums.size()-1;
        int first = -1;
        while(low<=high)
        {
           int mid = high - (high-low)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]<target)
        
                low = mid+1;
            else
               high= mid-1;
            }
            return low;
        }
        
    };


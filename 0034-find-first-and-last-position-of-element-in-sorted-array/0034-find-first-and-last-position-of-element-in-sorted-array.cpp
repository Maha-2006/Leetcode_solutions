class Solution {
public:
    int find_first_position(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        int result = -1;
        while(left<=right)
        {
            int mid = left+(right-left)/2;
            if(nums[mid]==target)
            {
                result = mid;
                right = mid-1;
            }else if(nums[mid]>target)
            {
                right = mid - 1;//left occurence
            }
            else{
                left = mid+1;
            }
        }
        return result;
    }
    

    int find_last_position(vector<int>&nums,int target){
        int left=0,right = nums.size()-1;
        int result = -1;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(nums[mid]==target)
            {
                result = mid;
                left = mid+1; // right occurence
            }else if(nums[mid]<target)
            {
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return result;
    }
    vector<int> searchRange(vector<int>&nums,int target){
        int left = find_first_position(nums,target);
        int right = find_last_position(nums,target);

        return {left,right};
    }
};
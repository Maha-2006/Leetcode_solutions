class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left_Index = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int right_Index = lower_bound(nums.begin(),nums.end(),target+1)-nums.begin();

        if(left_Index==right_Index){
            return {-1,-1};
        }
        return {left_Index,right_Index-1};
    }
};
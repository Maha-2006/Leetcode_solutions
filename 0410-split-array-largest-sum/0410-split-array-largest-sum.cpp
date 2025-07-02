class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans = high;

        while(low<=high){
            int mid = (low+high)/2;
            int partitions = 1;
            int Sum = 0;
            for(int i=0;i<nums.size();i++){
                if(Sum + nums[i]>mid){
                    partitions++;
                    Sum = nums[i];
                }else{
                    Sum += nums[i];
                }
            }
            if(partitions > k){
               low = mid + 1;
            }else{ 
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};
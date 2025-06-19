class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int res=1, minEle = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]-minEle>k){
                res++;
                minEle = nums[i];
            }
        }
        return res;
    }
};
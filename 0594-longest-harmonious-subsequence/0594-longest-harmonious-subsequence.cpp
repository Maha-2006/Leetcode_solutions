class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        int res=0;
        int l=0, r=1;
        sort(nums.begin(),nums.end());
        while(r<n){
            while(nums[r]-nums[l]>1)l++;
            if(nums[r]-nums[l]==1) res = max(res,r-l+1);
            r++;
        }
        return res;
    }
};
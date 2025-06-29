class Solution {
public:
 const int MOD = 1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> pow(n,1);
        for(int i=1;i<n;i++){
            pow[i] = (pow[i-1]<<1)%MOD;
        }
        int l = 0,h= n-1;
        int res = 0;
        while(l<=h){
            if(nums[l]+nums[h]<=target){
                res= (res+pow[h-l])%MOD;
                l++;
            }else{
                h--;
            }
        }
        return res;
    }
};
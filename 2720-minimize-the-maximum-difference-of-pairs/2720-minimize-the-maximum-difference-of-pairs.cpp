class Solution {
public:
    bool possiblePairs(vector<int>& nums, int diff, int p){
        int n = nums.size();
        int pairs = 0;
        for(int i=0;i<n-1;i++){
            if(nums[i+1]-nums[i]<=diff){
                pairs++;
                i++;
            }
        }
        return pairs >= p; 
    }
    int minimizeMax(vector<int>& nums, int p){
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int l=0,h=nums[n-1]-nums[0];
        int res = 0;
        while(l<=h){
            int m = (l+h)/2;
            if(possiblePairs(nums,m,p)){
                res = m;
                h = m - 1;
            }
            else{
                l = m+1;
            }
        }
        return res;
    }
};
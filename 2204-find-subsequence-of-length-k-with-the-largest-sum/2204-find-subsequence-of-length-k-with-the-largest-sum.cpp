class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans;
        vector<int> temp = nums;
        unordered_map<int,int> mp;
        sort(nums.begin(),nums.end(),greater<int>());

        for(int i=0;i<k;i++)
        mp[nums[i]]++;
    

    for(int i=0;i<temp.size();i++){
        if(mp[temp[i]]-->0)
        ans.push_back(temp[i]);
    }
        return ans;
    }
};
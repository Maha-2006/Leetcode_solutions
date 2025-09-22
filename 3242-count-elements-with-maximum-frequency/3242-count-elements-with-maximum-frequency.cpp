class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
       int n = nums.size();
       unordered_map<int,int> mp;
       int currF = 0, maxF = 0,sumF = 0;
       for(int i=0;i<n;i++){
        mp[nums[i]]++;
        currF = mp[nums[i]];
        if(currF>maxF){
            maxF = currF;
            sumF = currF;
        }
        else if(currF==maxF){
            sumF += maxF; 
        }
       }
       return sumF;
    }
};
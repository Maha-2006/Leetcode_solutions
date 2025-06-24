class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> result;

        for(int j=0;j<nums.size();++j){
            if(nums[j]==key){
                int start = max(0,j-k);
                int end = min((int)nums.size()-1,j+k);
                for(int i=start;i<=end;++i){
                    result.insert(i);
                }
            }
        }
        return vector<int>(result.begin(),result.end());
        
    }
};
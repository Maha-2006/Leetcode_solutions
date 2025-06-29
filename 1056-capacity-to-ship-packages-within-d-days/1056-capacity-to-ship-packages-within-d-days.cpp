class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);

        while(low<=high){
            int mid = (low+high)/2;

            int rdays=1,load = 0;//rdays = required_days
            for(int w:weights){
                if(load+w>mid){
                    rdays++;
                    load = w;
                }else{
                    load += w; 
                }
            }
            if(rdays<=days){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};
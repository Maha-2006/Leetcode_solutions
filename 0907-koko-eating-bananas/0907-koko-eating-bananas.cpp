class Solution {
public:

    bool canEatAll(vector<int>&piles, int h, long long k){
        int th = 0;
        for(int bananas:piles){
            th += (bananas+k-1)/k;
            if(th > h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1, high = *max_element(piles.begin(),piles.end());
        int result = high;

        while(low<=high){
            long long mid = (low+high)/2;
            if(canEatAll(piles,h,mid)){
                result = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return result;
        
    }
};
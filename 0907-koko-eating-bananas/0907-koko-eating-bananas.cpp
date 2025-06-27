class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1;
        long  long high = *max_element(piles.begin(),piles.end());
        long long result = high;

        while(low<=high){
            long long mid = (low+high)/2;
            long long th = 0;
        
        for(int bananas: piles){
            th += (bananas+mid-1)/mid;
        }
        if(th <= h ){
            result = mid;
            high = mid -1;
        }else{
            low = mid+1;
        }
        }
        return result;
    }
    
};
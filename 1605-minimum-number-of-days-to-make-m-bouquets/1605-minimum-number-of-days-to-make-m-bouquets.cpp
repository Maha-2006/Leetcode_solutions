class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ((long long )m*k > n )return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int  high = *max_element(bloomDay.begin(),bloomDay.end());

        while(low<=high){
            int mid = (low+high) /2;
            int cnt = 0, boq=0;

            for(int bloom : bloomDay){
                if(bloom <= mid) cnt++;
                else cnt = 0;

                if(cnt == k){
                    boq++;
                    cnt = 0;
                }
            }
            if(boq>=m) high = mid -1;
            else low = mid + 1;
        }
        return low;
    }
};
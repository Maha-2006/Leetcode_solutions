class Solution {
public:
    int findLucky(vector<int>& arr) {
     int freq[501] = {0};

     for(int i=0;i<arr.size();i++){
        freq[arr[i]]++;
     }

    int lucky = -1;
     for(int i=1;i<=500;i++){
        if(freq[i] == i){
            lucky = i;
        }
     }
     return lucky;
    }
};
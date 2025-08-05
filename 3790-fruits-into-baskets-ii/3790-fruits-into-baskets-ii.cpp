class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> usedBaskets(n,false);
        int unplacedCount = 0;

        for(int i=0;i<n;i++){
            bool placed = false;
            for(int j=0;j<n;j++){
                if(!usedBaskets[j] && baskets[j]>=fruits[i]){
                    usedBaskets[j] = true;
                    placed = true;
                    break;
                }
            }
            if(!placed){
                unplacedCount++;
            }
        }
        return unplacedCount;
    }
};
#define ll long long
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long mask = 0;
        for(int i=0;i<min(63,(int)operations.size());i++){
            mask |= (1ll * operations[i]<<i);
        }
        return 'a' + (__builtin_popcountll((k-1)&mask))%26;
    }
};
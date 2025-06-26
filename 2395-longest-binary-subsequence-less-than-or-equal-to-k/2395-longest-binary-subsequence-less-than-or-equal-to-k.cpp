class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int cntZeroes = 0, cntOnes = 0;
        long long sum = 0;

        for(int i=0;i<n;++i){
            if(s[i]=='0') cntZeroes++;
        }
        int power = 0;

        for(int i=n-1;i>=0;--i){
            if(s[i]=='1'){
                if(power<64){
                    sum += pow(2,power);
                    if(sum<=k){
                        cntOnes++;
                    }else break;
                }else break;
            }
            power++;
        }
        return cntOnes+cntZeroes;
    }
};
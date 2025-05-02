class Solution {
public:
    string pushDominoes(string dominoes) {
        int last_L = -1, last_R = -1;
        int n = dominoes.size();

        for (int pos = 0; pos < n; pos++) {
            if (dominoes[pos] == 'L') {
                if (last_R > last_L) {
                    doubleDominoPush(last_R, pos, dominoes);
                } else {
                    leftDominoPush(last_L + 1, pos, dominoes);
                }
                last_L = pos;
            }
            else if (dominoes[pos] == 'R') {
                if (last_R > last_L) {
                    rightDominoPush(last_R, pos, dominoes);
                }
                last_R = pos;
            }
        }

        if (last_R > last_L) {
            rightDominoPush(last_R, n - 1, dominoes);
        }

        return dominoes;
    }

private:
    void leftDominoPush(int start, int end, string &dominoes) {
        for (int i = start; i < end; ++i) {
            dominoes[i] = 'L';
        }
    }

    void rightDominoPush(int start, int end, string &dominoes) {
        for (int i = start + 1; i <= end; ++i) {
            dominoes[i] = 'R';
        }
    }

    void doubleDominoPush(int R, int L, string &dominoes) {
        int left = R + 1;
        int right = L - 1;
        while (left < right) {
            dominoes[left++] = 'R';
            dominoes[right--] = 'L';
        }
    }
};

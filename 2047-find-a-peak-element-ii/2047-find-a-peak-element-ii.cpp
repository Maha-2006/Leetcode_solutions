class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
int low =0,high = n-1;
        while(low<=high){
            int midCol = (low+high)/2;

            int maxRow = 0;
            for(int i=1;i<m;i++){
                if(mat[i][midCol]>mat[maxRow][midCol]){
                    maxRow = i;
                }
            }
            int left = (midCol-1>=0) ?mat[maxRow][midCol-1]:-1;
            int right = (midCol+1<n) ?mat[maxRow][midCol+1]:-1;
            int curr = mat[maxRow][midCol];

            if(curr>left && curr>right){
                return {maxRow, midCol};
            }
            else if(right>curr){
                low = midCol+1;
            }else{
                high = midCol -1;
            }
        }
        return {-1,-1};
    }
};
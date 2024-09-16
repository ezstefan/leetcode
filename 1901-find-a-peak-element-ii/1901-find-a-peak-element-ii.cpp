class Solution {
    int findMaxInd(vector<vector<int>>& mat, int n, int m, int col) {
        int maxValue = -1;
        int ind = -1;

        for (int i = 0; i<n; i++) {
            if(mat[i][col] > maxValue) {
                maxValue = mat[i][col];
                ind = i;
            }
        }
        return ind;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0;
        int high = m-1;

        while(low <=high) {
            int mid = low + (high - low) / 2;
            int maxIndexRow = findMaxInd(mat, n, m, mid);
            int left = mid - 1 >= 0 ? mat[maxIndexRow][mid - 1] : -1;
            int right = mid + 1 < m ? mat[maxIndexRow][mid + 1] : -1;

            if(mat[maxIndexRow][mid] > left && mat[maxIndexRow][mid] > right) {
                return {maxIndexRow, mid};
            }
            else if(mat[maxIndexRow][mid] < left) {
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return {-1,-1};
        
    }
};
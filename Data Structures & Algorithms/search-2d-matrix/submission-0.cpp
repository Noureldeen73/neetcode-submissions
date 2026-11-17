class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int row = -1;
        int l = 0, r = m - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(matrix[mid][0] <= target && target <= matrix[mid][n - 1]){
                row = mid;
                break;
            }
            else if (target < matrix[mid][0]){
                r  = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        if(row == -1){
            return false;
        }
        l = 0, r = n - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(matrix[row][mid] == target){
                return true;
            }
            else if(matrix[row][mid] > target){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return false;
    }
};

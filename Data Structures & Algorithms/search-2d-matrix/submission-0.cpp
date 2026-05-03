class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col = matrix[0].size();
        int rows = matrix.size();
        int currRow = 0;
        while(currRow < rows){
            if(matrix[currRow][0] <= target && matrix[currRow][col-1] >= target){
                int left = 0, right = col-1;
                while(left <= right){
                    int mid = left + (right - left)/2;
                    if(matrix[currRow][mid] == target)
                        return true;
                    else if(matrix[currRow][mid] < target)
                        left = mid+1;
                    else
                        right = mid-1;
                }
                return false;
            }
            else
                currRow++;
        }
        return false;
    }
};

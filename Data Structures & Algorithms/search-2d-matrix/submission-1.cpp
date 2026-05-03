class Solution {
public:
// the matrix can be considered as a array of size (m*n) and then we can
// apply binary search on it to get log(m*n) time complexity.

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col = matrix[0].size();
        int row = matrix.size();
        int left = 0, right = row*col-1;

        while(left <= right){
            int mid = left + (right - left)/2;
            int value = matrix[mid / col][mid % col];
            if(value == target)
                return true;
            else if(value > target)
                right = mid-1;
            else
                left = mid+1;
        }
        return false;
    }
};

class Solution {
public:
    int findMin(vector<int> &nums) {
        int minEle = INT_MAX;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            minEle = min(minEle, nums[i]);
        }
        return minEle;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;

        sort(nums.begin(), nums.end());
        int maxLen = 1, len = 1;

        for(int i = 0; i < n-1; i++){
            if(nums[i] == nums[i+1] - 1)
                len++;
            else if(nums[i] == nums[i+1])
                continue;
            else
                len = 1;
            maxLen = max(len, maxLen);
        }
        return maxLen;
    }
};

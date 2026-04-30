class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;

        int maxLen = 1, len = 1, j= 0;

        for(int i = 0; i < n; i++){
            int curr = nums[i];
            len = 1, j = 0;
            while(j < n){
                if(curr+1 == nums[j] && i != j){
                    curr++;
                    len++;
                    j = 0;
                }
                else
                    j++;
            }
            maxLen = max(len, maxLen);
        }
        return maxLen;
    }
};

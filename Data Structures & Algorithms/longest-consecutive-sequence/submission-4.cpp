class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;

        unordered_set<int>hash(nums.begin(), nums.end());
        int len = 1, maxLen = 1;
        int curr;

        for(int item : hash){
            len = 1;
            while(true){
                if(hash.find(item+1) != hash.end()){
                    len++;
                    item++;
                }
                else
                    break;
            }
            maxLen = max(len, maxLen);
        }
        return maxLen;
    }
};

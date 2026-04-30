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
            if(hash.find(item - 1) == hash.end()){
                while(hash.find(item+1) != hash.end()){
                    len++;
                    item++;
                }
                maxLen = max(len, maxLen);
            }
        }
        return maxLen;
    }
};

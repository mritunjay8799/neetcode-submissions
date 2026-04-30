class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n < 2) return n;
        int  maxLen = 0, left = 0;
        unordered_set<char>check;
        for(int rgt = 0; rgt<n; rgt++){
           while(check.count(s[rgt])){
            check.erase(s[left]);
            left++;
           }
           check.insert(s[rgt]);
           maxLen = max(maxLen, rgt-left+1);
        }
        return maxLen;
    }
};

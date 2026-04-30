class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n < 2) return n;
        int curlen = 0, maxLen = 0;
        for(int i = 0; i<n; i++){
            curlen = 1;
            unordered_set<char>check;
            check.insert(s[i]);
            for(int j = i+1; j<n; j++){
                if(!check.count(s[j])){
                    curlen++;
                    check.insert(s[j]);
                }
                else{
                    check.erase(s[j]);
                    break;
                }
            }
            maxLen = max(maxLen, curlen);
        }
        return maxLen;
    }
};

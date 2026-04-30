class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n < 2) return n;
        int curlen = 0, maxLen = 0;
        unordered_map<char, int>mp;
        for(int i = 0; i<n; i++){
            mp[s[i]]++;
            curlen = 1;
            for(int j = i+1; j<n; j++){
                if(mp[s[j]] == 0){
                    curlen++;
                    mp[s[j]]++;
                }
                else{
                    mp[s[j]] = 1;
                    mp.clear();
                    break;
                }
            }
            maxLen = max(maxLen, curlen);
        }
        return maxLen;
    }
};

class Solution {
/*
For every starting index i, you extend j to the right. At each step you track
how many times the most frequent character appears in [i...j]. The number of 
replacements needed is window length - maxFreq. If that's ≤ k, it's valid. 
If not, break — expanding further only makes it worse.
*/
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxLen = 0, left = 0, maxFreq = 0;
        int count[26] = {0};
        for(int rgt = 0; rgt<n; rgt++){
            count[s[rgt]-'A']++;
            maxFreq = max(maxFreq, count[s[rgt]-'A']);
            while((rgt-left+1)-maxFreq > k){
                count[s[left]-'A']--;
                maxFreq = max(maxFreq, count[s[rgt]-'A']);
                left++;
            }
            maxLen = max(maxLen, (rgt-left+1));
        }
        return maxLen;
    }
};

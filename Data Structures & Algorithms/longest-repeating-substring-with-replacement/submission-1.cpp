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
        int maxLen = 0;
        for(int i = 0; i<n; i++){
            int count[26] = {0};
            int maxFreq = 0;
            for(int j = i; j<n; j++){
                count[s[j] - 'A']++;
                maxFreq = max(maxFreq, count[s[j]-'A']);
                if((j-i+1) - maxFreq <= k){
                    maxLen = max(maxLen, j-i+1);
                }
                else
                    break;
            }
        }
        return maxLen;
    }
};

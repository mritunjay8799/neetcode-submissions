#include<bits/stdc++.h>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string prefix = "";
        for(int i = 0; i<strs[0].size(); i++){
            char ch = strs[0][i];

            for(int j = 1; j < n; j++){
                if(i > strs[j].size() || ch != strs[j][i])
                    return prefix;
            }

            prefix += ch;
        }
        return prefix;
    }
};
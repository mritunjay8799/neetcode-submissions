#include <cstring>
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int count[26] = {0};
        int n1 = s1.size();
        for(int i = 0; i<n1; i++){
            count[s1[i]-'a']++;
        }

        for(int i = 0; i<s2.size(); i++){
            int temp_count[26];
            memcpy(temp_count, count, sizeof(count));
            int track = 0;
            for(int j = i; j < s2.size(); j++){
                if(temp_count[s2[j]-'a']){
                    temp_count[s2[j]-'a']--;
                    track++;
                }else{
                    break;
                }
            }
            if(track == n1)
                return true;
        }
        return false;
    }
};

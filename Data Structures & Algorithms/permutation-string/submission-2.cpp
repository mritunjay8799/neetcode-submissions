#include <cstring>
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>count_s1(26,0);
        vector<int>count_s2(26,0);
        int n1 = s1.size();
        int left = 0;
        for(int i = 0; i<n1; i++){
            count_s1[s1[i]-'a']++;
            count_s2[s2[i]-'a']++;
        }

        for(int rgt = n1; rgt < s2.size(); rgt++){
            if(count_s1 == count_s2)
                return true;
            else{
                count_s2[s2[left]-'a']--;
                count_s2[s2[rgt]-'a']++;
                left++;
            }
        }
        return (count_s1 == count_s2);
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int>umap;
        int length_s = s.size();
        int length_t = t.size();
        if(length_s != length_t)
            return false;
        else{
            for(int i = 0; i < length_s; i++){
                umap[s[i]] += 1;
                umap[t[i]] -= 1;
            }
            for(auto const& [key, value] : umap){
                if(value != 0)
                    return false;
            }
        }
        return true;
    }
};

public class Solution {
    public int FirstUniqChar(string s) {
        Dictionary<char, int> dict = new();
        foreach(char c in s)
        {
            if(!dict.ContainsKey(c))
            {
                dict[c] = 1;
            }
            else{
                dict[c]++;
            }
        }

        for(int i = 0; i < s.Length; i++)
        {
            if(dict[s[i]] == 1)
                return i;
        }
        return -1;
    }
}
public class Solution {
    public bool hasDuplicate(int[] nums) {
        Dictionary<int, int> mp = new();
        int n = nums.Length;

        foreach(int num in nums){
            if(!mp.ContainsKey(num))
            {
                mp[num] = 1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
}
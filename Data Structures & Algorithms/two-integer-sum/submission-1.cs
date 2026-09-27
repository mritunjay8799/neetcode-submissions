public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int,int> dict = new();
        for(int i = 0; i<nums.Count(); i++)
        {
            int diff = target - nums[i];
            if(!dict.ContainsKey(diff))
            {
                dict[nums[i]] = i;
            }
            else
            {
                return [dict[diff], i];
            }
        }
        return [0,0];
    }
}

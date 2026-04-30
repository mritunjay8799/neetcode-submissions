class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        int j = 1;
        int length = nums.size();
        unordered_map<int, int>mp;
        for(int i = 0; i < length; i++){
            mp[nums[i]] = i;
        }
        if(nums[i]+nums[j] == target)
            return {0,1};
        else{
            for(int i = 0; i<length; i++){
                int diff = target - nums[i];
                if(mp.count(diff) && mp[diff] != i)
                    return {i, mp[diff]};
            }
        }
        return {};
    }
};

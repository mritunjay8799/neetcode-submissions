class Solution {
public:
    using List = vector<int>;
    using Result = vector<List>;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        Result result;
        List currentItems;
        backtrack(currentItems, 0, 0, nums, target, result);
        return result;
    }

    void backtrack(List& current, int idx, int sum, List& nums, int target, Result& result){
        if(sum == target){
            result.push_back(current);
            return;
        }

        if(sum > target || idx >= nums.size()) return;
        // exclude - not take scenario    
        backtrack(current, idx+1, sum, nums, target, result);

        // include - to take scenario
        current.push_back(nums[idx]);
        backtrack(current, idx, sum+nums[idx], nums, target, result);
        current.pop_back();
    }
};

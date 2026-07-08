class Solution {
public:
    using List = vector<int>;
    using Result = vector<List>;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        Result result;
        List current;
        sort(candidates.begin(), candidates.end());
        backtrack(current, 0, candidates, target, result);
        return result;
    }

    void backtrack(List& current, int idx, List& nums, int target, Result& result){
        if(target == 0){
            result.push_back(current);
            return;
        }
        if(target < 0 || idx >= nums.size()) return;

        // include - to take
        current.push_back(nums[idx]);
        backtrack(current, idx+1, nums, target-nums[idx], result);
        current.pop_back();

        while(idx + 1 < nums.size() && nums[idx] == nums[idx+1]){
            idx++;
        }
        //exclude - not to take 
        backtrack(current, idx+1, nums, target, result);
    }
};

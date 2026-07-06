class Solution {
public:
    using List = vector<int>;
    using Result = vector<List>;
    vector<vector<int>> subsets(vector<int>& nums) {
        Result result;
        List currentState;
        backtrack(currentState, 0, nums, result);
        return result;
    }

    void backtrack(List& currentState, int startIdx, List nums, Result& result){
        result.push_back(currentState);

        for(int i = startIdx; i < nums.size(); i++){
            currentState.push_back(nums[i]);

            backtrack(currentState, i+1, nums, result);

            currentState.pop_back();
        }
    }
};

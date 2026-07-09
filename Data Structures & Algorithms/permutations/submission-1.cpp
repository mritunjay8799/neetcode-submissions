class Solution {
public:
// OPTIMAL APPROACH

    using List = vector<int>;
    using Result = vector<List>;
    vector<vector<int>> permute(vector<int>& nums) {
        List current;
        Result result;
        List used(nums.size(), 0);
        backtrack(nums, current, used, result);
        return result;
    }

    void backtrack(List& nums, List& current, List& used, Result& result){
        if(current.size() == nums.size()){
            result.push_back(current);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(used[i]) continue;
            used[i] = 1;
            current.push_back(nums[i]);
            backtrack(nums, current, used, result);
            current.pop_back();
            used[i] = 0;
        }
    }
};

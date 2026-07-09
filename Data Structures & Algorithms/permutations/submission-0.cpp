class Solution {
public:
// BRUTE FORCE APPROACH

    using List = vector<int>;
    using Result = vector<List>;
    vector<vector<int>> permute(vector<int>& nums) {
        List current;
        Result result;
        backtrack(nums, current, result);
        return result;
    }

    void backtrack(List& nums, List& current, Result& result){
        if(current.size() == nums.size()){
            // filtering duplicates
            unordered_set<int> seen(current.begin(), current.end());
            if(seen.size() == nums.size())
                result.push_back(current);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            current.push_back(nums[i]);
            backtrack(nums, current, result);
            current.pop_back();
        }
    }
};

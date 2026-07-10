class Solution {
public:
    using List = vector<int>;
    using Result = vector<List>;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        List current;
        Result result;
        sort(nums.begin(), nums.end());
        backtrack(current, nums, 0, result);
        return result;
    }

    void backtrack(List& current, List& nums, int idx, Result& result){
        result.push_back(current);

       for(int i = idx; i < nums.size(); i++){
         if(i > idx && nums[i] == nums[i-1]) continue;

         current.push_back(nums[i]);
         backtrack(current, nums, i+1, result);
         current.pop_back();
       }

    }
};

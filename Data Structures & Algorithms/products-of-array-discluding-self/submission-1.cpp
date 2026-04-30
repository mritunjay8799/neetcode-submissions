class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1, zeroCount = 0;
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] != 0)
                product = product * nums[i];
            else
                zeroCount++;
        }

        vector<int>result;
        if(zeroCount > 1)
            return vector<int>(nums.size(),0);
        int temp;

        for(int i = 0; i < nums.size(); i++){
            if(zeroCount > 0)
                temp = nums[i] == 0 ? product : 0;
            else
                temp = product/nums[i];

            result.push_back(temp);
        }
        return result;
        
    }
};

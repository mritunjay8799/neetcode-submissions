class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector<int>prefixProd(length, 1);
        vector<int>suffixProd(length, 1);
        vector<int>result;
        int preProd = 1, suffProd = 1;
        for(int i = 1; i<nums.size(); i++){
            int j = nums.size() - 1 - i;
            preProd = nums[i-1]*preProd;
            suffProd = nums[j+1]*suffProd;
            prefixProd[i] = preProd;
            suffixProd[j] = suffProd;
        }
        for(int i = 0; i < length; i++){
            result.push_back(prefixProd[i]*suffixProd[i]);
        }
        return result;
        
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;

        for(int i = 1; i<n; i++){
            if(nums[i] == nums[i-1]){

                for(int j = i; j<n-1; j++){
                    nums[j] = nums[j+1];
                } 
                n--;
                i--;
            }
        }
        return n;
    }
};
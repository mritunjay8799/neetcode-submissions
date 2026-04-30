class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;

        int i = 0;
        int j = 1;
        while(i < j && j < n){
            if(nums[j] == nums[i])
                j++;
            else{
                nums[i+1] = nums[j];
                i++;
                j++;
            }
        }
        return i+1;
    }
};
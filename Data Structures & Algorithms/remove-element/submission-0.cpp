class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int w = 0;
        for(int r = 0; r < n; r++){
            if(nums[r] != val){
                nums[w] = nums[r];
                w++;
            }
        }
        return w;
    }
};
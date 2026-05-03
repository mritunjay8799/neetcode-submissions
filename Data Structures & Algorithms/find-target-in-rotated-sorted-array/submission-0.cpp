class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int index = -1;
        int left = 0, right = n-1;
        while(left <= right){
            int mid = left + (right - left)/2;

            // if found return index
            if(nums[mid] == target) return mid;

            // checking if left half is sorted
            else if(nums[left] <= nums[mid]){
                // if element in left half
                if(target >= nums[left] && target < nums[mid])
                    right = mid - 1;

                // element in right half
                else{
                    left = mid+1;
                }
            } 
            // if right half is sorted
            else{
                //element in right half
                if(target > nums[mid] && target <= nums[right])
                    left = mid+1;

                //element in left half    
                else
                    right = mid-1;
            }
        }
        return index;
    }
};

class Solution {
public:
/*
First check if left half is sorted or right half, then in both check if target 
is in sorted half or unsorted half and update left & right accordingly.

Since here there can be duplicates and when nums[l] == nums[mid], it becomes 
difficult to judge which side is sorted, for that just move l by 1, l++;
*/

    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(nums[mid] == target) return true;

             if (nums[l] == nums[mid]) {
                l++;
                continue;
            }

            else if(nums[l] < nums[mid]){
                if(target >= nums[l] && target < nums[mid])
                    r = mid-1;
                else
                    l = mid+1;
            }
            else{
                if(target > nums[mid] && target <= nums[r])
                    l = mid+1;
                else
                    r = mid-1;
            }
        }
        return false;
    }
};
class Solution {
public:
/*
Boyer-Moore Voting Algorithm  - 

The idea: the majority element appears more than half the time. So if you 
cancel out each occurrence of the majority element with a different element, 
the majority element will still survive.
*/
    int majorityElement(vector<int>& nums) {
       int n = nums.size();
       int candidate = 0, count = 0;
       for(int num : nums){
        if(count == 0)
            candidate = num;
        if(num == candidate)
            count++;
        else
            count--;
       }
       return candidate;
    }
};
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>mp;
        int sum = 0, count = 0;
        for(int num : nums){
            sum+=num;
            // 0 to current element subarray
            if(sum == k)
                count++;
            // subarrays between 0 to current element
            if(mp.count(sum-k))
                count+=mp[sum-k];
            mp[sum]++;
        }
        return count;
    }
};
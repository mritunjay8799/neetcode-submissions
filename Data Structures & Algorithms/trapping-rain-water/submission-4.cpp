class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int totalWater = 0;
        int left = 0, right = n-1, maxLeft = h[0], maxRight = h[n-1];

        while(left <= right){
            if(maxLeft < maxRight){
                maxLeft = max(maxLeft, h[left]);
                totalWater += maxLeft - h[left];
                left++;
            }
            else{
                maxRight = max(maxRight, h[right]);
                totalWater += maxRight - h[right];
                right--;
            }
        }
        return totalWater;
    }
};

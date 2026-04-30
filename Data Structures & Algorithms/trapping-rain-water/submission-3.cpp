class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int>left;
        vector<int>right(n);
        int maxLeft = 0, maxRight = 0, maxArea = 0;
        for(int i = 0; i<n; i++){
            maxLeft = max(maxLeft, h[i]);
            left.push_back(maxLeft);
        }

        for(int i = n-1; i>=0; i--){
            maxRight = max(maxRight, h[i]);
            right[i] = maxRight;
        }
        int totalWater = 0;
        for(int i = 0; i<n; i++){
            int area = min(left[i], right[i])-h[i];
            totalWater += area ;
        }
        return totalWater;
    }
};

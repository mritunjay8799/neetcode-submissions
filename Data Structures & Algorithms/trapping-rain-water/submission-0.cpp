class Solution {
public:
    int findLeftMax(int idx, vector<int>&h){
        int maxi = 0;
        for(int i = 0; i<=idx; i++){
            maxi = max(maxi,h[i]);
        }
        return maxi;
    }
    
    int findRightMax(int idx, vector<int>&h){
        int maxi = 0;
        int n = h.size();
        for(int i = n-1; i>=idx; i--){
            maxi = max(maxi,h[i]);
        }
        return maxi;
    }

    int trap(vector<int>& h) {
        int n = h.size();
        int totalWater = 0;
        for(int i = 0; i<n; i++){
            int leftMax = findLeftMax(i, h);
            int rightMax = findRightMax(i, h);
            int maxWater = min(leftMax, rightMax)-h[i];
            totalWater += maxWater;
        }
        return totalWater;
    }
};

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0, area = 0;
        int n = heights.size();
        int left = 0, right = n-1;
        while(left < right){
            int area = (right-left)*min(heights[left], heights[right]);
            if(heights[left] < heights[right])
                left++;
            else
                right--;
            maxArea = max(area,maxArea);
        }
        return maxArea;
    }
};

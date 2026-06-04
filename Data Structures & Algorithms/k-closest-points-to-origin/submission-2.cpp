class Solution {
public:
/*
 In distance-comparison problems (like the Euclidean distance formula 
 sqrt{x^2 + y^2}, you don't actually need to calculate the square root. 
 Comparing the squared distances (x^2 + y^2) yields the exact same relative
 ordering, executes faster, and completely avoids floating-point or truncation
 issues.
*/
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       using element = pair<int, int>;
       priority_queue<element>maxHeap;
       int n = points.size();

       for(int i = 0; i < n; i++){
        int dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];
        maxHeap.push({dist, i});
        if(maxHeap.size() > k)
            maxHeap.pop();
       }

       vector<vector<int>> res;

       while(!maxHeap.empty()){
        res.push_back(points[maxHeap.top().second]);
        maxHeap.pop();
       }
       
       return res;
    }
};

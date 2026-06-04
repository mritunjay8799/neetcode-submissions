class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       using element = pair<int, vector<int>>;
       priority_queue<element>maxHeap;
       int n = points.size();
       for(int i = 0; i < n; i++){
        int dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];
        maxHeap.push({dist, points[i]});
        if(maxHeap.size() > k)
            maxHeap.pop();
       }
       vector<vector<int>> res;
       while(!maxHeap.empty()){
        res.push_back(maxHeap.top().second);
        maxHeap.pop();
       }
       return res;
    }
};

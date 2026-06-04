class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxHeap;
        int n = stones.size();
        for(int i = 0; i < n; i++){
            maxHeap.push(stones[i]);
        }
        while(maxHeap.size() > 1){
            int a = maxHeap.top();
            maxHeap.pop();
            int b = maxHeap.top();
            maxHeap.pop();
            int res = (a-b);
            if(res > 0)
                maxHeap.push(res);
        }
        if(maxHeap.size() > 0)
            return maxHeap.top();
        return 0;
    }
};

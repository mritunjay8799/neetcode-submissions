class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>umap;
        for(int i = 0; i<nums.size(); i++){
            umap[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
                    greater<pair<int, int>>> minHeap;
        for(auto& item : umap){
            minHeap.push({item.second, item.first});
            if(minHeap.size() > k)
                minHeap.pop();
        }

        vector<int>res;
        for(int i =0; i<k; i++){
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return res;
    }
};

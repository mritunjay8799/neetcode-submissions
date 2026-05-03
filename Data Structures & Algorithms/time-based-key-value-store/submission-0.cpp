class TimeMap {
public:
map<string, vector<pair<string, int>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string, int>>value;
        value = mp[key];
        int n = value.size();
        int left = 0, right = n-1;
        string result;
        while(left <= right){
            int mid = left + (right - left)/2;

            if(value[mid].second <= timestamp){
                result = value[mid].first;
                left = mid+1;
            }
            else
                right = mid-1;
        }
        return result;
    }
};

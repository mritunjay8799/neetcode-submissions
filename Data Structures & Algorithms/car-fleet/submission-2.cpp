class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& s) {
        int n = pos.size();
        vector<pair<int, double>>car;
        int fleetCount = 1;

        for(int i = 0; i<n; i++){
            car.push_back({pos[i], (double)(target - pos[i])/s[i]});
        }
        sort(car.begin(), car.end(), [](auto& a, auto& b){
            return a.first > b.first;
        });

        double slowest = car[0].second;
        for(int i = 1; i<n; i++){
            if(car[i].second > slowest){
                fleetCount++;
                slowest = car[i].second;
            }
        }

        return fleetCount;
    }
};

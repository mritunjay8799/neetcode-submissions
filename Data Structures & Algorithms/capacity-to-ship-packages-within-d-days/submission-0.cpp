#include<bits/stdc++.h>
class Solution {
public:
    int shipWithinDays(vector<int>& w, int d) {
        int r = accumulate(w.begin(), w.end(),0);
        int l = *max_element(w.begin(), w.end());
        int minCap = INT_MAX;
        while(l <= r){
            int mid = l + (r-l)/2;
            int days = 1;
            int cap = 0;
            for(int i = 0; i < w.size(); i++){
                cap += w[i];
                if(cap > mid){
                    days++;
                    cap = w[i];
                }
            }
            if(days <= d){
                minCap = min(minCap, mid);
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return minCap;
    }
};
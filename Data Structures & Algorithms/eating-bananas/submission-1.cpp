#include <algorithm> 

/*
This code is Correct but since its Brute Force we are getting TLE
*/


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxEle = *max_element(piles.begin(), piles.end());
        int speed = INT_MAX;
        int left = 1, right = maxEle;
        while(left <= right){
            int count_h = 0;
            int mid = left + (right - left)/2;
            for(int j = 0; j < n; j++){
                count_h += piles[j] / mid;
                if(piles[j] % mid)
                    count_h++;

                if(count_h > h)
                    break;   
            }
            if(count_h <= h){
                speed = min(speed, mid);
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return speed;
    }
};

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
        for(int i = 1; i <= maxEle; i++){
            int count_h = 0;
            for(int j = 0; j < n; j++){
                count_h += piles[j]/i;
                if(piles[j]%i)
                    count_h++;

                if(count_h > h)
                    break;   
            }
            if(count_h <= h)
                return i;
        }
        return maxEle;
    }
};

// Problem - 1011

// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

// O(nlogn) time complexity and O(1) space complexity solution

class Solution {
public:
    bool canBeShipped(vector <int>& weights, int D, int maxCapacity) {
        int days = 1;
        int capacity = 0;
        for(int w : weights) {
            capacity += w;
            if(capacity > maxCapacity) {
                days++;
                capacity = w;
            }
        }
        return days <= D;
    }
    
    int shipWithinDays(vector<int>& weights, int D) {
        int h = accumulate(weights.begin(), weights.end(), 0);
        int l = *max_element(weights.begin(), weights.end());
        while(l < h) {
            int mid = (h-l)/2 + l;
            if(canBeShipped(weights, D, mid)) {
                h = mid;
            }
            else {
                l = mid+1;
            }
        }
        return l;
    }
};

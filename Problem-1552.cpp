// Problem - 1552

// https://leetcode.com/problems/magnetic-force-between-two-balls/

// O(nlogm) time complexity and O(1) space complexity solution

class Solution {
public:
    bool canBePlaced(vector <int> &pos, int m, int d) {
        int lastPlaced = pos[0];
        m--;
        for(int i = 1; i < pos.size() && m > 0; i++) {
            if(pos[i] - lastPlaced >= d) {
                m--;
                lastPlaced = pos[i];
            }
        }
        return m == 0;
    }
    
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(), pos.end());
        int n = pos.size();
        int l = 1, h = pos[n-1] - pos[0];
        while(l <= h) {
            int mid = (h-l)/2 + l;
            if(canBePlaced(pos, m, mid)) {
                l = mid+1;
            }
            else {
                h = mid-1;
            }
        }
        return l-1;
    }
};

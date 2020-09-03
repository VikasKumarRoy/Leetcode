// Problem - 220

// https://leetcode.com/problems/contains-duplicate-iii/

// O(nlogn) time complexity and O(n) space complexity solution

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        vector <pair <long, long>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());
        int i = 0, j = 1;
        while(j < n && i < n) {
            if(abs(v[j].first - v[i].first) > t) {
                i++;
            }
            else {
                if(i != j && abs(v[i].second-v[j].second) <= k)
                    return true;
                j++;
            }
            
        }
        return false;
    }
};

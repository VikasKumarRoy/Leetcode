// Problem - 349

// https://leetcode.com/problems/intersection-of-two-arrays/

// O(n+m) time complexity and O(n+m) space complexity solution

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set <int> s1, s2;
        for(int val : nums1)
            s1.insert(val);
        for(int val : nums2) {
            if(s1.count(val))
                s2.insert(val);
        }
        return vector <int> (s2.begin(), s2.end());
    }
};
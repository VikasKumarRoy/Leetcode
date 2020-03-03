// Problem - 1346

// https://leetcode.com/problems/check-if-n-and-its-double-exist/

// O(n) time complexity and O(n) space complexity solution single pass

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set <int> us;
        int ctr = 0; 
        for(int val : arr) {
            ctr += val == 0;
            if(val != 0 && (us.count(2 * val) || (val % 2 == 0 && us.count(val / 2))))
                return true;
            us.insert(val);
        }
        return (ctr > 1 ? true : false);
    }
};

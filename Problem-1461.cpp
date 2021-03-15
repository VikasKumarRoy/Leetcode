// Problem - 1461

// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        if(k > n)
            return false;
        unordered_set <int> us;
        int num = 0;
        int i = 0;
        while(i < k) {
            int bit = s[i++] - '0';
            num = (num << 1) | bit;
        }
        us.insert(num);
        for(; i < n; i++) {
            int bit = s[i] - '0';
            num = (num << 1) | bit;
            // Clear kth bit
            num &= ~(1 << k);
            us.insert(num);
        }
        return us.size() == pow(2, k);
    }
};

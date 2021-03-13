// Problem - 1461

// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/

// O(n) time complexity and O(n) space solution

class Solution {
    public boolean hasAllCodes(String s, int k) {
        int n = s.length();
        if(k > n)
            return false;
        HashSet<Integer> us = new HashSet<Integer>();
        int num = 0;
        int i = 0;
        while(i < k) {
            int bit = s.charAt(i++) - '0';
            num = (num << 1) | bit;
        }
        us.add(num);
        for(; i < n; i++) {
            int bit = s.charAt(i) - '0';
            num = (num << 1) | bit;
            // Clear kth bit
            num &= ~(1 << k);
            us.add(num);
        }
        return us.size() == Math.pow(2, k);
    }
}

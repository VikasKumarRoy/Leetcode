// Problem - 556

// https://leetcode.com/problems/next-greater-element-iii/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        next_permutation(s.begin(), s.end());
        int ans = stoll(s);
        if(ans > INT_MAX || ans <= n)
            return -1;
        return ans;
    }
};
 
// OR Without using STL library

class Solution {
public:
    int nextGreaterElement(int n) {
        long long next = nextPermutation(to_string(n));
        if(next == -1 || next > INT_MAX || next == n)
            return -1;
        return next;
    }
    
    long long nextPermutation(string s) {
        int n = s.length();
        int i = n-2;
        for(; i>=0; i--) {
            if(s[i] < s[i+1])
                break;
        }
        if(i == -1)
            return -1;
        int j = n-1;
        for(; j >=0; j--) {
            if(s[j] > s[i])
                break;
        }
        swap(s[i], s[j]);
        reverse(s.begin()+i+1, s.end());
        return stoll(s);
    }
};

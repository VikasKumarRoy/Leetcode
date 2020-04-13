// Problem - 509

// https://leetcode.com/problems/fibonacci-number/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int fib(int N) {
        if(N < 2)
            return N;
        vector <int> v(N+1);
        v[0] = 0;
        v[1] = 1;
        for(int i = 2; i <= N; i++) {
            v[i] = v[i-1] + v[i-2];
        }
        return v[N];
    }
};

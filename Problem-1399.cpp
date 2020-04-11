// Problem - 1399

// https://leetcode.com/problems/count-largest-group/

// Time Complexity O(nlogn) and O(1) space ignoring stack space

class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while(n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    
    int countLargestGroup(int n) {
        vector <int> freq(37, 0);
        int mx = 0, res = 0;
        for(int i = 1; i <= n; i++) {
            mx = max(mx, ++freq[digitSum(i)]);
        }
        for(int i = 0; i < 37; i++) {
            if(freq[i] == mx)
                res++;
        }
        return res;
    }
};



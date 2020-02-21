// Problem - 204

// https://leetcode.com/problems/count-primes/

// O(n*log(log(n))) time complexity and O(n) space complexity solution using Sieve of Eratosthenes

class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        vector <bool> isPrime(n+1, 1);
        for(int i = 2; i < sqrt(n); i++) {
            if(isPrime[i])
                for(int j = i*i; j < n; j += i)
                    isPrime[j] = 0;
        }
        for(int i = 2; i < n; i++)
            if(isPrime[i])
                ans++;
        return ans;
    }
};

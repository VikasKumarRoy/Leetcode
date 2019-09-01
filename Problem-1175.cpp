//Problem - 1175
// https://leetcode.com/problems/prime-arrangements/

// O(n) time comlexity 

class Solution {
public:
    int mod = 1e9 + 7;
    
    bool isPrime(int n) { 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
   
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false;   
    return true; 
    }
    
    long long fact(int n) {
        long long fac = 1;
        int x = 2;
        while(x <= n) {
            fac = (fac*x)%mod;
            x++;
        }
        return fac;
    }
    
    int numPrimeArrangements(int n) {
        int primes = 0, nonprimes = 0;
        for(int i = 1; i <= n; i++)
            if(isPrime(i))
                primes++;
        nonprimes = n - primes;
        return (fact(primes) * fact(nonprimes) )%mod;
    }
};
   
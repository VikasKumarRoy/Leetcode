// Problem - 299

// https://leetcode.com/problems/bulls-and-cows/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    string getHint(string secret, string guess) {
        vector <int> freq(10, 0);
        int a = 0, b = 0;
        for(int i = 0; i < secret.length(); i++) {
            if(secret[i] == guess[i])
                a++;
            else
                freq[secret[i]-'0']++;
        }
        for(int i = 0; i < secret.length(); i++) {
            if(secret[i] != guess[i] && freq[guess[i]-'0'] > 0) {
                freq[guess[i]-'0']--;
                b++;
            }
        }
        return to_string(a) + 'A' + to_string(b) + 'B';
    }
};

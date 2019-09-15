//Problem - 1189
// https://leetcode.com/problems/maximum-number-of-balloons/

// Time Complexity O(n) and O(1) space 

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector <int> freq(26);
        for(char c : text) {
            freq[c - 'a']++;
        }
        freq['l' - 'a'] /= 2;
        freq['o' - 'a'] /= 2;
        return min(freq['a'-'a'], min(freq['b'-'a'], min(freq['l'-'a'], min(freq['o'-'a'], freq['n'-'a']))));
    }
};


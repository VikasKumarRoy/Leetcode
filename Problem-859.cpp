// Problem - 859

// https://leetcode.com/problems/buddy-strings/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.length() != B.length())
            return false;
        if(A == B) {
            vector <int> freq(26, 0);
            for(char c : A) {
                if(++freq[c-'a'] > 1)
                    return true;
            }
            return false;
        }
        int j = 0, k = 0, ctr = 0;
        for(int i = 0; i < A.length(); i++) {
            if(A[i] != B[i]) {
                ctr++;
                if(ctr == 1)
                    j = i;
                else if(ctr == 2)
                    k = i;
                else if(ctr > 2)
                    return false;
            }
        }
        swap(A[j], A[k]);
        return A == B;
    }
};

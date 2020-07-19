// Problem - 67

// https://leetcode.com/problems/add-binary/

// O(n+m) time complexity and O(1) space complexity solution

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length()-1;
        int j = b.length()-1;
        string ans;
        bool carry =0;
        while(i >= 0 && j >= 0) {
            if(a[i] == '1' && b[j] == '1') {
                if(carry)
                    ans = '1' + ans;
                else
                    ans = '0' + ans;
                carry = 1;
            }
            else if(a[i] == '1' || b[j] == '1') {
                if(carry) {
                    ans = '0' + ans;
                }
                else {
                    ans = '1' + ans;
                }
            }
            else {
                if(carry) {
                    ans = '1' + ans;
                    carry = 0;
                }
                else {
                    ans = '0' + ans;
                }                
            }
            i--, j--;
        }
        while(i >= 0) {
            if(a[i] == '1') {
                if(carry)
                    ans = '0' + ans;
                else {
                    ans = '1' + ans;
                }
            }
            else {
                if(carry) {
                    ans = '1' + ans;
                    carry = 0;
                }
                else
                    ans = '0' + ans;
            }
            i--;
        }
        while(j >= 0) {
            if(b[j] == '1') {
                if(carry)
                    ans = '0' + ans;
                else {
                    ans = '1' + ans;
                }
            }
            else {
                if(carry) {
                    ans = '1' + ans;
                    carry = 0;
                }
                else
                    ans = '0' + ans;
            }
            j--;
        }
        if(carry)
            ans = '1' + ans;
        return ans;
    }
};

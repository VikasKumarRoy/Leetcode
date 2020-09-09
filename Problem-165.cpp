// Problem - 165

// https://leetcode.com/problems/compare-version-numbers/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    int compareVersion(string ver1, string ver2) {
        ver1 += '.';
        ver2 += '.';
        int i = 0, j = 0;
        int n = ver1.length(), m = ver2.length();
        while(i < n && j < m) {
            string a, b;
            while(ver1[i] != '.')
                a += ver1[i++];
            while(ver2[j] != '.')
                b += ver2[j++];
            int num1 = stoi(a), num2 = stoi(b);
            if(num1 != num2)
                return num1 > num2 ? 1 : -1;
            i++, j++;
        }
        if(i != n) {
            while(i < n) {
                string s;
                while(ver1[i] != '.')
                    s += ver1[i++];
                if(stoi(s) > 0)
                    return 1;
                i++;
            }
        }
        if(j != m) {
            while(j < m) {
                string s;
                while(ver2[j] != '.')
                    s += ver2[j++];
                if(stoi(s) > 0)
                    return -1;
                j++;
            }
        }
        return 0;
    }
};

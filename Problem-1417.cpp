 
// Problem - 1417

// https://leetcode.com/problems/reformat-the-string/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    string reformat(string s) {
        string num, alpha, ans, greater, smaller;
        for(char c : s) {
            if(isalpha(c))
                alpha += c;
            else
                num += c;
        }
        int diff = abs((int)(alpha.size() - num.size()));
        if(diff > 1)
            return "";
        if(alpha.length() > num.length()) {
            greater = alpha;
            smaller = num;
        }
        else {
            greater = num;
            smaller = alpha;
        }
        int i = 0;
        while(i < smaller.length()) {
            ans += greater[i];
            ans += smaller[i++];
        }
        if(i < greater.length())
            ans += greater[i];
        return ans;
    }
};

// Problem - 187

// https://leetcode.com/problems/repeated-dna-sequences/

// O(n) time complexity and O(n) space complexity solution

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length() < 10)
            return {};
        unordered_set <string> us, ans;
        string str = s.substr(0, 10);
        us.insert(str);
        for(int i = 10; i < s.length(); i++) {
            str += s[i];
            str = str.substr(1, 11);
            if(us.count(str)) {
                ans.insert(str);
            }
            else {
                us.insert(str);
            }
        }
        vector <string> ans_vec(ans.begin(), ans.end());
        return ans_vec;
    }
};

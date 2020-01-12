// Problem - 1317

// https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/

// O(nlog10n) time complexity and O(1) space complexity solution

cclass Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        string s1, s2;
        for(int i = 1; i < n; ++i) {
            int j = n - i;
            s1 = to_string(i);
            s2 = to_string(j);
            if(s1.find('0') == string::npos && s2.find('0') == string::npos)
                return {i, j};
        }
    return {};
}
};
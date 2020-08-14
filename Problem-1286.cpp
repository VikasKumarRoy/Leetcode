// Problem - 1286

// https://leetcode.com/problems/iterator-for-combination/submissions/

// O(n+r-1Cr) where n is length of characters and r is the combinationLength 
// O(n*r) space complexity solution

class CombinationIterator {
public:
    vector <string> v;
    int pos;
    
    void generateCombination(string s, int n, vector <string> &v, int pos, string t) {
        if(t.length() == n) {
            v.push_back(t);
            return;
        }
        if(pos >= s.length() || t.length() > n)
            return;
        for(int i = pos; i < s.length(); i++) {
            generateCombination(s, n, v, i+1, t+s[i]);
        }
        return;
    }
    
    
    CombinationIterator(string characters, int combinationLength) {
        generateCombination(characters, combinationLength, v, 0, "");
        pos = 0;
    }
    
    string next() {
        return v[pos++];
    }
    
    bool hasNext() {
        return pos < v.size();
    }
};

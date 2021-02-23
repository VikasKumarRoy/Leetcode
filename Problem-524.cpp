// Problem - 524

// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/

// O(nxlog(n) + nx) time complexity and O(log(n)) space complexity solution where x is average word length

class Solution {
public:
    bool canBeConverted(string str, string target) {
        int n = str.length(), m = target.length();
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(str[i] != target[j]) {
                i++;
            }
            else {
                i++, j++;
            }
        }
        return j == m;
    }
    
    static bool customComp(string a, string b) {
        if(a.length() == b.length())
            return a < b;
        return a.length() > b.length();
    }
    
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), customComp);
        for(string v : d) {
            if(canBeConverted(s, v))
                return v;
        }
        return "";
    }
};

// OR O(nx) time and O(x) space solution without sorting

class Solution {
public:
    bool canBeConverted(string str, string target) {
        int n = str.length(), m = target.length();
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(str[i] != target[j]) {
                i++;
            }
            else {
                i++, j++;
            }
        }
        return j == m;
    }

    string findLongestWord(string s, vector<string>& d) {
        string ans;
        for(string v : d) {
            if(canBeConverted(s, v)) {
                if(ans.length() < v.length())
                    ans = v;
                else if(ans.length() == v.length() && v < ans)
                    ans = v;
            }
        }
        return ans;;
    }
};

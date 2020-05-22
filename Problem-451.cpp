// Problem - 451

// https://leetcode.com/problems/sort-characters-by-frequency/

// Time Complexity O(nlogn) and O(1) space complecity solution

class Solution {
public:
    string frequencySort(string s) {
        unordered_map <char, int> m;
        for(char c : s) {
            m[c]++;
        }
        set <pair <int, char>> st;
        for(auto it : m) {
            st.insert({it.second, it.first});
        }
        string ans;
        for(auto it = st.rbegin(); it != st.rend(); it++) {
            int freq = (*it).first;
            while(freq--) {
                ans += (*it).second;
            }
            
        }
        return ans;
    }
};

//        OR
// O(n) time comlexity solution using bucket sort

class Solution {
public:
    string frequencySort(string s) {
        unordered_map <char, int> m;
        string ans;
        for(char c : s) {
            m[c]++;
        }
        vector <string> bucket(s.size()+1);
        for(auto it : m) {
            bucket[it.second] += it.first;
        }
        for(int i = bucket.size()-1; i >= 0; i--) {
            string str = bucket[i];
            if(str.length()) {
                for(char c : str) {
                    int freq = i;
                    while(freq--)
                        ans += c;
                }
            }
        }
        return ans;
    }
};

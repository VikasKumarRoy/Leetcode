//Problem - 1268

// https://leetcode.com/problems/search-suggestions-system/

// O(nlogn)  time complexity and O(1) space complexity sol using binary search

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector <vector<string>> ans(searchWord.length());
        sort(products.begin(), products.end());
        for(int i = 0; i < searchWord.length(); i++) {
            string s = searchWord.substr(0, i+1);
            auto it = lower_bound(products.begin(), products.end(), s);
            while(it != products.end() && s == (*it).substr(0, i+1) &&  ans[i].size() < 3) {
                ans[i].push_back(*it);
                it++;
            }
        }
        return ans;
    }
};
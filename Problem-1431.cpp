// Problem  - 1431

// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

// O(n) time complexity and O(1) space

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = *max_element(candies.begin(), candies.end());
        vector <bool> ans(candies.size());
        for(int i = 0; i < candies.size(); i++) {
            ans[i] = (candies[i]+extraCandies) >= mx; 
        }
        return ans;
    }
};

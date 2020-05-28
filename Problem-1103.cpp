// Problem - 1103

// https://leetcode.com/problems/distribute-candies-to-people/

// O(n) time complexity and O(n) space solution

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector <int> ans(num_people);
        if(candies == 0)
            return ans;
        int ctr = 1;
        int i = 0;
        while(ctr <= candies) {
            ans[i++] += ctr;
            candies -= ctr;
            ctr++;
            if(i == ans.size())
                i = 0;
        }
        ans[i] += candies;
        return ans;
    }
};

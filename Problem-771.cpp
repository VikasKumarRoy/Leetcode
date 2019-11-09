//Problem - 771

// https://leetcode.com/problems/jewels-and-stones/

// O(n)  time complexity for dfs and O(m) space complexity sol

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set <char> hash;
        int ans = 0;
        for(auto c : J)
            hash.insert(c);
        for(auto c : S)
            if(hash.find(c) != hash.end())
                ans++;
        return ans;
    }
};

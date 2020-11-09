// Problem - 1423

// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

// O(n) time complexity and O(1) space complexity solution sliding window

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int sz = n-k;
        int windowSum = accumulate(cardPoints.begin(), cardPoints.begin()+sz, 0);
        int ans = total-windowSum, i = 0, j = sz;
        while(j < n) {
            windowSum += (cardPoints[j++] - cardPoints[i++]);
            ans = max(ans, total-windowSum);
        }
        return ans;
    }
};

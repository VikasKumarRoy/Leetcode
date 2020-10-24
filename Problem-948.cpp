// Problem - 948

// https://leetcode.com/problems/bag-of-tokens/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());
        int score = 0, ans = 0;
        int i = 0, j = tokens.size()-1;
        while(i <= j) {
            if(P >= tokens[i]) {
                P -= tokens[i++];
                ans = max(ans, ++score);
            }
            else if(score > 0){
                score--;
                P += tokens[j--];
            }
            else {
                break;
            }
        }
        return ans;
    }
};

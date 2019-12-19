//Problem - 985

// https://leetcode.com/problems/sum-of-even-numbers-after-queries/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector <int> ans;
        int sum = 0;
        for(int val : A)
            sum += val&1 ? 0 : val;
        for(auto quer : queries) {
            if(!(A[quer[1]] & 1))
                sum -= A[quer[1]];
            A[quer[1]] += quer[0];
            if(!(A[quer[1]] & 1))
                sum += A[quer[1]];
            ans.push_back(sum);
        }
        return ans;
    }
};
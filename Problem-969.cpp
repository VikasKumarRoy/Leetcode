  
// Problem - 969

// https://leetcode.com/problems/pancake-sorting/

// O(n^2) time complexity and O(1) space complexity solution

class Solution {
public:
    void reverse(vector <int> &v, int n) {
        for(int i = 0; i <= n/2; i++)
            swap(v[i], v[n-i]);
    }
    
    vector<int> pancakeSort(vector<int>& A) {
        vector <int> ans;
        int n = A.size();
        int pos = n-1;
        while(pos) {
            int ind = 0;
            for(int i = 1; i <= pos; i++) {
                if(A[i] < A[ind]) {
                    ind = i;
                }
            }
            if(ind != pos) {
                if(ind != 0) {
                    reverse(A, ind);
                    ans.push_back(ind+1);
                }
                reverse(A, pos);
                ans.push_back(pos+1);
            }
            pos--;
        }
        ans.push_back(n);
        return ans;
    }
};

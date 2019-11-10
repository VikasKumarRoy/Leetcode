//Problem - 1252

// https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/

// O(m+n+q)  time complexity for dfs and O(m+n) space complexity sol

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector <int> row(n, 0), col(m, 0);
	    for(auto a : indices) {
	        row[a[0]]++;
	        col[a[1]]++;
	    }
        int even = 0, odd = 0, ans = 0;;
	    for(int i = 0; i < m; i++)
	       col[i] & 1 ? odd++ : even++;
	    for(int i = 0; i < n; i++)
	        ans += row[i] & 1 ? even : odd;
	    return ans;
	}
};

// Problem - 1649

// https://leetcode.com/problems/create-sorted-array-through-instructions/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int tree[400004];
    
    int query(int pos, int i, int j, int low, int high) {
        if (low >= i && high <= j) return tree[pos];
        if (i > high || j < low) return 0;
        int mid = (high - low) / 2 + low;
        return query(2*pos, i, j, low, mid) + query(2*pos+1, i, j, mid+1, high);
    }
    
    void update(int i, int delta, int low, int high, int pos) {
        if (i < low || i > high) return;
        if (low == high) {
            tree[pos] += delta;
            return;
        }
        int mid = (high - low) / 2 + low;
        update(i, delta, low, mid, 2*pos);
        update(i, delta, mid+1, high, 2*pos+1);
        tree[pos] = tree[2*pos] + tree[2*pos+1];
    }
    
    int createSortedArray(vector<int>& instructions) {
        int ans = 0;
        const int MAXN = 1e5 + 1;
        const int MOD = 1e9 + 7;
        for (auto instr : instructions) {
            ans = (ans + std::min(
                query(1, 0, instr-1, 0, MAXN),
                query(1, instr+1, MAXN, 0, MAXN)
                )) % MOD;
            update(instr, 1, 0, MAXN, 1);
        }
        return ans;
    }
};

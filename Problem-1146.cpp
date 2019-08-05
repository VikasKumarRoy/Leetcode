//Problem  - 1146
// https://leetcode.com/problems/snapshot-array/


// O(n) space complexity solution passes all test cases
class SnapshotArray {
public:
    int snaps = 0;
    unordered_map <int, vector <pair <int, int>>> mp;

    SnapshotArray(int length) {
        snaps = 0;
    }
    
    void set(int index, int val) {
        mp[index].push_back({snaps, val});
    }
    
    int snap() {
        snaps++;
        return snaps-1;
    }
    
    int get(int index, int snap_id) {
        auto it = upper_bound(begin(mp[index]), end(mp[index]), pair<int, int>(snap_id, INT_MAX));
        return it == begin(mp[index]) ? 0 : prev(it)->second;
    }
};

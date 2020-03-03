 
// Problem - 705

// https://leetcode.com/problems/design-hashset/

// O(1) time complexity and O(1) space complexity solution using bfs

class MyHashSet {
public:
    bool hash[1000001];
    
    MyHashSet() {
        memset(hash, false, 1000001);
    }
    
    void add(int key) {
        hash[key] = true;
    }
    
    void remove(int key) {
        hash[key] = false;
    }

    bool contains(int key) {
        return hash[key];
    }
};

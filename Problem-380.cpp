// Problem - 380

// https://leetcode.com/problems/insert-delete-getrandom-o1/

// O(1) time complexity all operations and O(n) space complexity solution using hashmap and vector

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map <int, int> hash;
    vector <int> v;
    
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(hash.count(val))
            return false;
        hash[val] = v.size();
        v.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!hash.count(val))
            return false;
        int last = v[v.size()-1];
        hash[last] = hash[val];
        v[hash[val]] = last;
        v.pop_back();
        hash.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(v.empty())
            return 0;
        return v[rand()%v.size()];
    }
};

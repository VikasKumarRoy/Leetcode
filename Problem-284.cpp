// Problem - 284

// https://leetcode.com/problems/peeking-iterator/

// O(1) time complexity and O(1) space complexity solution

/*
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
    bool has_next;
    int next_val;
    
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    has_next = Iterator::hasNext();
        if(has_next)
            next_val = Iterator::next();
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return next_val;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int temp = next_val;
        has_next = Iterator::hasNext();
        if(has_next)
            next_val = Iterator::next();
        return temp;
	}
	
	bool hasNext() const {
	    return has_next;
	}
};

//Problem - 26
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

// Time complextiy O(n)

class Solution {
public:
    int removeDuplicates(vector <int>& v) {
        if(v.size() > 1){
            auto it = v.begin();
        while(it < prev(v.end())) {
            if(*it == *next(it))
                v.erase(it);
            else
                it++;
        }
    }
        return v.size();
    }
};

//OR

class Solution {
public:
    int removeDuplicates(vector <int>& v) {
        if(v.size() < 2)
            return v.size();
        v.erase(unique(v.begin(), v.end()), v.end());
        return v.size();
    }
};

   
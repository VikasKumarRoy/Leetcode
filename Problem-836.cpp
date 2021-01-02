// Problem - 836

// https://leetcode.com/problems/rectangle-overlap/

// O(1) time complexity and O(1) space complexity solution

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if(rec2[0] >= rec1[2] || rec1[0] >= rec2[2])
            return false;
        if(rec2[1] >= rec1[3] || rec1[1] >= rec2[3])
            return false;
        if(rec1[0] == rec1[2] || rec1[1] == rec1[3] || rec2[0] == rec2[2] || rec2[1] == rec2[3])
            return false;
        return true;
    }
};

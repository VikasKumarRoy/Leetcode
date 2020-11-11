// Problem - 593

// https://leetcode.com/problems/valid-square/

// O(1) time complexity and O(1) space complexity solution by comparing 4 sides and diagnol lenght

class Solution {
public:
    const float PI = 3.141592;
    
    int distance(vector <int>& p1, vector <int>& p2) { 
        return (pow(p1[0] - p2[0], 2) +  pow(p1[1] - p2[1], 2)); 
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector <int> v(6);
        v[0] = distance(p1, p2);
        v[1] = distance(p1, p3);
        v[2] = distance(p1, p4);
        v[3] = distance(p2, p3);
        v[4] = distance(p2, p4);
        v[5] = distance(p3, p4);
        sort(v.begin(), v.end());
        if(v[0] == 0 || v[1] != v[0] || v[0] != v[2] || v[0] != v[3])
            return false;
        if(v[4] != v[5])
            return false;
        return true;
    }
};

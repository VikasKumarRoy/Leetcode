// Problem - 593

// https://leetcode.com/problems/valid-square/

// O(1) time complexity and O(1) space complexity solution

class Solution {
public:
    const float PI = 3.141592;
    
    float distance(vector <int>& p1, vector <int>& p2) { 
        return sqrt(pow(p1[0] - p2[0], 2) +  pow(p1[1] - p2[1], 2) * 1.0); 
    }
    
    float getAngle(vector <int>& p1, vector <int>& p2) {
        if(abs(p1[0] - p2[0]) == 0)
            return 90;
        float slope = (float)(p1[1] - p2[1]) / (p1[0] - p2[0]);
        float A = float(atan(slope)) * 180 / PI;
        cout << A << endl;
        return A;
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        float l1 = distance(p1, p2);
        float l2 = distance(p1, p3);
        float l3 = distance(p1, p4);
        if(l2 > l1 && l2 > l3) {
            swap(p2, p3);
        }
        if(l3 > l1 && l3 > l2) {
            swap(p2, p4);
        }
        l1 = distance(p1, p2);
        l2 = distance(p3, p4);
        if(l1 != l2)
            return false;
        float angle =  abs(getAngle(p1, p2) - getAngle(p3, p4));
        float t = 0.01;
        cout << "angle " << angle <<endl;
        if(angle > 90+t || angle < 90-t)
            return false;
        return true;
    }
};

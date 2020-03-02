//Problem - 605

// https://leetcode.com/problems/can-place-flowers/

// Time Complexity O(n) and O(1) space 

class Solution {
public:
    bool isSafe(vector<int>& v, int i) {
        if(v.size() < 2)
            return v[0] == 0;
        if(i > 0 && i < v.size()-1 && v[i-1] == 0 && v[i+1] == 0)
            return 1;
        else if(i == 0 && v[i+1] == 0 || i == v.size()-1 && v[i-1] == 0)
            return 1;
        return 0;
    }
    
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i = 0; i < flowerbed.size() && n >= 0; i++) {
            if(flowerbed[i] == 0 && isSafe(flowerbed, i)) {
                cout << i << endl;
                flowerbed[i] = 1;
                n--;
            }
        }
        return (n <= 0);
    }
};

//Problem - 1276

// https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if(cheeseSlices == 0 && tomatoSlices == 0)
            return {0, 0};
        for(int i = 0, j = cheeseSlices; i < cheeseSlices; i++, j--) {
            if(4*i + 2*j == tomatoSlices)
                return {i, j};
        }
        return {};
    }
};

// O(1) time complexity and O(1) space complexity solution using linear equation

class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if(tomatoSlices % 2 != 0) return {};
        int jumbo = tomatoSlices/2-cheeseSlices;
        int small = cheeseSlices - jumbo;
        if(jumbo < 0 || small < 0) 
            return {};
        return {jumbo, small};
 
    }
};
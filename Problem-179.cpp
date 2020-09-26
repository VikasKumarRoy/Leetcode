// Problem - 179

// https://leetcode.com/problems/largest-number/

// O(knlogn) time complexity and O(n) space complexity solution where k is avg len of strings

class Solution {
public:
    static bool mycomp(const int& a,const int& b) {
        string x = to_string(a);
        string y = to_string(b);
        return x+y < y+x;
    }
    
    string largestNumber(vector<int>& nums) {
        string ans;
        if(*max_element(nums.begin(), nums.end()) == 0)
            return "0";
        sort(nums.begin(), nums.end(), mycomp);
        for(int i = nums.size()-1; i >= 0; i--) {
            ans += to_string(nums[i]);
        }        
        return ans;
    }
};

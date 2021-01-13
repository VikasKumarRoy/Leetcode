// Problem - 881

// https://leetcode.com/problems/boats-to-save-people/

// O(nlogn) time complexity and O(1) space complexity solution

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = people.size()-1, ans = 0;
        while(i <= j) {
            ans++;
            if(people[i] + people[j] <= limit)
                i++;
            j--;
        }
        return ans;
    }
};

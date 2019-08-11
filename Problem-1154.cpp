//Problem  - 1154
// https://leetcode.com/problems/ordinal-number-of-date/


// O(n) solution passes all tc

class Solution {
public:
    int dayOfYear(string date) {
        vector <int> month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int year = 0, mon = 0, day = 0, ans = 0;
        for(int i = 0; i < 4; i++)
            year = year * 10 + (date[i] - '0');
        for(int i = 5; i < 7; i++)
            mon = mon * 10 + (date[i] - '0');
        for(int i = 8; i < 10; i++)
            day = day * 10 + (date[i] - '0');
         if (year % 4 == 0) {
          if (year % 100 == 0)
            {
                if (year % 400 == 0)
                    month[1] = 29;
            }
            else
                month[1] = 29;
        }
        //cout << year << " " << mon << " " << day;
        ans = accumulate(month.begin(), month.begin() + (mon-1), 0) + day;
        return ans;
    }
};
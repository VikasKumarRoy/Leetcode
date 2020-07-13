// Problem - 1507

// https://leetcode.com/problems/reformat-date/

// O(n) time complexity and O(1) space complexity solution where n = no. of chars

class Solution {
public:
    vector <string> months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    
    string reformatDate(string date) {
        stringstream ss(date);
        string day, month, year;
        ss >> day >> month >> year;
        int m = find(months.begin(), months.end(), month) - months.begin() + 1;
        month = to_string(m);
        if(m < 10)
            month = "0" + month;
        if(day.length() ==  3)
            day = "0" + day;
        day = day.substr(0, 2);
        return year+'-'+month+'-'+day;
    }
};

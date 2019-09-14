//Problem - 732
// https://leetcode.com/problems/my-calendar-iii/

// Time Complexity O(n^2) and O(n) space 

class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    map <int, int> m;
    int book(int start, int end) {
        m[start]++;
        m[end]--;
        int k = 0;
        int mx = 0;
        for(auto p : m) {
            k += p.second;
            mx = max(mx, k);
        }
        return mx;
    }
};


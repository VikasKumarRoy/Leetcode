//Problem - 729
// https://leetcode.com/problems/my-calendar-i/

// Time Complexity O(n) and O(n) space 

class MyCalendar {
public:
    vector <pair<int, int>> v; 
    
    MyCalendar() {
        
    }
    
    bool book(int s, int e) {
        if(v.size() == 0)
        {
            v.push_back({s, e});
            return 1;
        }
        
        for(auto p : v) {
            if(e <= p.first || s >= p.second ) {
                continue;
            }
            return false;
        }
        v.push_back({s, e});
        return true;
    }
};
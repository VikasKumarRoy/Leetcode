//Problem - 731
// https://leetcode.com/problems/my-calendar-ii/

// Time Complexity O(n^2) and O(n) space 

class MyCalendarTwo {
public:
    set < pair<int, int> > overlap, non_overlap; 
    
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(auto p : overlap) {
            if(p.first < end && start < p.second)
                return false;
        }
        for(auto p : non_overlap) {
            if(p.first < end && start < p.second)
                overlap.insert({max(start, p.first), min(end, p.second)});
        }
        non_overlap.insert({start, end});
        return true;
    }
};

// Another Approach using map with O(n^2) time and O(n) space complexity

class MyCalendarTwo {
public:
    map <int, int> m;
    
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        m[start]++;
        m[end]--;
        
        int sum;
        for(auto p : m) {
            sum += p.second;
            if(sum >= 3) {
                m[start]--;
                m[end]++;
                return false;
            }
        }
        return true;
    }
};

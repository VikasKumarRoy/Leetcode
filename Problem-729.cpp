//Problem - 729
// https://leetcode.com/problems/my-calendar-i/

// Time Complexity O(n^2) and O(n) space 

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

// Time Complexity O(nlogn) and O(n) space 

class MyCalendar {
public:
    set <pair<int, int>> st; 
    
    MyCalendar() {
        
    }
    
    bool book(int s, int e) {
        auto it = st.lower_bound({s, INT_MIN});
        if(it == st.end()) {
            if(!st.empty()) {
                auto pre = prev(it);
                if(s < pre->second)
                    return false;
            }
        }
        
        else if(it == st.begin()) {
            if(e > it->first)
                return false;
        }
        
        else {
            auto pre = prev(it);
            if(s < pre->second || e > it->first)
                return false;
        }
        st.insert({s, e});
        return true;
    }
};

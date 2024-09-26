class MyCalendar {
public:
    set<pair<int, int>> s; // multiset also works here
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = s.upper_bound({end, -1});
        if (it == s.begin()) {  // note that when a set is empty, s.begin() and s.end() are equal
            s.insert({start, end});
            return true;
        }
        advance(it, -1);
        int preStart = it->first, preEnd = it->second;
        if (start >= preEnd) {
            s.insert({start, end});
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
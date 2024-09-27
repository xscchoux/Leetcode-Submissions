// Use treemap, O(nlogn) for each call
class MyCalendarTwo {
public:
    map<int, int> hmap;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        hmap[start]++;
        hmap[end]--;
        int cnt = 0;
        for (auto &[k, v]:hmap) {
            cnt += v;
            if (cnt == 3) {
                hmap[start]--;
                hmap[end]++;
                if (hmap[start] == 0) {
                    hmap.erase(start);
                }
                if (hmap[end] == 0) {
                    hmap.erase(end);
                }
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */


// O(n) for each call, store double booked time spans in another vector
class MyCalendarTwo {
public:
    vector<pair<int, int>> booked, doubleBooked;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for (auto &[s, e]:doubleBooked) {
            if (max(s, start) < min(e, end)) {
                return false;
            }
        }

        for (auto &[s, e]:booked) {
            if (max(s, start) < min(e, end)) {
                doubleBooked.push_back({max(s, start), min(e, end)});
            }
        }

        booked.push_back({start, end});
        return true;
    }
};
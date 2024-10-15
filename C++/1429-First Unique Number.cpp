class FirstUnique {
public:
    unordered_map<int, int> count;
    deque<int> dq;
    FirstUnique(vector<int>& nums) {
        for (int num:nums) {
            count[num]++;
            dq.push_back(num);
        }
    }
    
    int showFirstUnique() {
        while (!dq.empty() && count[dq.front()] > 1) {
            dq.pop_front();
        }
        if (dq.empty()) return -1;
        return dq.front();
    }
    
    void add(int value) {
        count[value]++;
        dq.push_back(value);
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */



// Use list (not faster)
class FirstUnique {
public:
    list<int> ls;  // store unique values
    unordered_map<int, list<int>::iterator> hmap;
    FirstUnique(vector<int>& nums) {
        for (int num:nums) {
            add(num);
        }
    }
    
    int showFirstUnique() {
        if (!ls.empty()) {
            return ls.front();
        }
        return -1;
    }
    
    void add(int value) {
        if (!hmap.contains(value)) {
            ls.push_back(value);
            hmap[value] = --ls.end();
        } else if (hmap[value] != ls.end()) {
            ls.erase(hmap[value]);
            hmap[value] = ls.end();
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
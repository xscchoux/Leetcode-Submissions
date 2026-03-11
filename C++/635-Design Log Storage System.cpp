class LogSystem {
public:
    unordered_map<string, int> hmap = {{"Year", 4}, {"Month", 7}, {"Day", 10}, {"Hour", 13}, {"Minute", 16}, {"Second", 19}};
    vector<pair<string, int>> log;
    LogSystem() {

    }
    
    void put(int id, string timestamp) {
        log.push_back({timestamp, id});
    }
    
    vector<int> retrieve(string start, string end, string granularity) {
        vector<int> res;
        int len = hmap[granularity];
        string startString = start.substr(0, len), endString = end.substr(0, len);

        for (auto &s:log) {
            string sub = s.first.substr(0, len);
            if (sub>=startString && sub<=endString) {
                res.push_back(s.second);
            }
        }
        return res;
    }
};


// multimap + binary search
class LogSystem {
public:
    unordered_map<string, int> hmap = {{"Year", 4}, {"Month", 7}, {"Day", 10}, {"Hour", 13}, {"Minute", 16}, {"Second", 19}};
    multimap<string, int> mmap;
    LogSystem() {
        
    }
    
    void put(int id, string timestamp) {
        mmap.insert({timestamp, id});
    }
    
    vector<int> retrieve(string start, string end, string granularity) {
        int endIdx = hmap[granularity];

        // Note that ':' has ASCII value 58, and '0' has ASCII value 48
        for (int i=endIdx; i<end.size(); i++) {
            if (end[i] != ':') {
                start[i] = '0';
                end[i] = '9';
            }
        }

        auto leftIt = mmap.lower_bound(start);
        auto rightIt = mmap.upper_bound(end);

        vector<int> res;
        for (auto it = leftIt; it != rightIt; it++) {
            res.push_back(it->second);
        }

        return res;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */
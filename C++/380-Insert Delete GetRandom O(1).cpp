class RandomizedSet {
public:
    unordered_map<int, int> hmap;
    vector<int> res;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (hmap.find(val) != hmap.end()) return false;
        res.push_back(val);
        hmap[val] = res.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (hmap.find(val) == hmap.end()) return false;

        res[hmap[val]] = res.back();
        hmap[res.back()] = hmap[val];
        hmap[val] = res.size()-1;

        res.pop_back();
        hmap.erase(val);

        return true;
    }
    
    int getRandom() {
        return res[rand() % res.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
class TwoSum {
public:
    unordered_map<int, int> cnt;
    TwoSum() {
        
    }
    
    void add(int number) {
        cnt[number]++;
    }
    
    bool find(int value) {
        if (value > 2e5 || value < -2e5) return false;
        if (value%2 == 0 && cnt.contains(value/2) && cnt[value/2] >= 2) {
            return true;
        }
        for (auto &[k, v]:cnt) {
            if (cnt.contains(value-k) && value-k != k) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
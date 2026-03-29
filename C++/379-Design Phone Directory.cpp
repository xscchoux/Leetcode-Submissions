class PhoneDirectory {
public:
    unordered_set<int> directories;
    PhoneDirectory(int maxNumbers) {
        for (int i=0; i<maxNumbers; i++) {
            directories.insert(i);
        }
    }
    
    int get() {
        if (directories.empty()) return -1;
        int num = *directories.begin();
        directories.erase(num);
        return num;
    }
    
    bool check(int number) {
        return directories.contains(number);
    }
    
    void release(int number) {
        directories.insert(number);
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */
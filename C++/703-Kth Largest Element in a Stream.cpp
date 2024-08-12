class KthLargest {
public:
    int k;
    multiset<int> mset;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num:nums) {
            mset.insert(num);
        }
    }
    
    int add(int val) {
        mset.insert(val);
        auto it = mset.rbegin();
        advance(it, k-1);
        return *it;
    }
};

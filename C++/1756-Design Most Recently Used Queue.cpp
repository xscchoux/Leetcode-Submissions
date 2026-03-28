// O(logn*logn)
class FenwickTree {
private:
    vector<int> bit; // Binary Indexed Tree
    int n;

public:
    // Constructor to initialize the Fenwick Tree with size `n`
    FenwickTree(int size) : n(size) {
        bit.resize(n + 1, 0); // 1-based indexing
    }

    // Add value `delta` at index `idx` (1-based index)
    void update(int idx, int delta) {
        while (idx <= n) {
            bit[idx] += delta;
            idx += idx & -idx; // Move to the next index
        }
    }

    // Get the prefix sum from 1 to `idx` (1-based index)
    int query(int idx) const {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx; // Move to the parent index
        }
        return sum;
    }

    // Get the range sum from `left` to `right` (1-based index)
    int rangeQuery(int left, int right) const {
        return query(right) - query(left - 1);
    }
};

class MRUQueue {
private:
    vector<int> values;
    FenwickTree* FT;
public:
    MRUQueue(int n) {
        values.resize(n+1);
        // iota(begin(values), end(values), 1);
        for (int i=1; i<=n; i++) {
            values[i] = i;
        }
        FT = new FenwickTree(n+2010);
    }
    
    int fetch(int k) {
        int left = 1, right = values.size()-1;
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (mid - FT->query(mid) >= k) {
                right = mid;
            } else {
                left = mid;
            }
        }

        int idx;
        if (left-FT->query(left) >= k) {
            idx = left;
        } else {
            idx = right;
        }

        FT->update(idx, 1);
        values.push_back(values[idx]);

        return values.back();
    }
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */



// Redo, use segment tree
class SGTree {
    vector<int> seg;
public:
    SGTree(int n) {
        seg.resize(4 * n + 1, 0);
    }

    void build(int ind, int low, int high, vector<int>& arr) {
        if (low == high) {
            seg[ind] = arr[low];
            return;
        }

        int mid = low + (high - low) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    int query(int ind, int low, int high, int l, int r) {
        // no overlap
        // l r low high or low high l r
        if (r < low || high < l) return 0;

        // complete overlap
        // [l low high r]
        if (low >= l && high <= r) return seg[ind];

        int mid = low + (high - low) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return (left + right);
    }

    void update(int ind, int low, int high, int i, int val) {
        if (low == high) {
            seg[ind] = val;
            return;
        }

        int mid = low + (high - low) / 2;
        if (i <= mid) update(2 * ind + 1, low, mid, i, val);
        else update(2 * ind + 2, mid + 1, high, i, val);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
};


// Note the way we initialize sgt
class MRUQueue {
public:
    vector<int> arr;
    SGTree sgt;
    int n;
    MRUQueue(int n) : sgt(n+2000){
        this->n = n;
        for (int i=1; i<=n; i++) {
            arr.push_back(i);
        }
        // sgt = new SGTree(n+2000);
    }
    
    int fetch(int k) {
        int left = 0, right = arr.size() - 1;
        // find the (k-1)th index
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (mid - sgt.query(0, 0, n+2000, 0, mid) >= k-1) {
                right = mid;
            } else {
                left = mid;
            }
        }

        int idx;
        if (left - sgt.query(0, 0, n+2000, 0, left) >= k-1) {
            idx = left;
        } else {
            idx = right;
        }
        
        sgt.update(0, 0, n+2000, idx, 1);
        arr.push_back(arr[idx]);

        return arr[idx];
    }
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */
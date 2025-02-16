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
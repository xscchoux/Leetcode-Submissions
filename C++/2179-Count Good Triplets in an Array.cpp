// TLE, unfortunately we cannot find index of a value in a multiset in O(logN) time
// SortedList in Python does support finding the index of a value in O(log N) time
class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int N = nums1.size();
        unordered_map<int, int> pos2;

        for (int i=0; i<N; i++) {
            pos2[nums2[i]] = i;
        }

        multiset<int> ms2; // store the indexes of visited nums1 values in nums2
        ms2.insert(pos2[nums1[0]]);
        vector<int> left(N, 0);

        for (int i=1; i<N; i++) {
            ms2.insert(pos2[nums1[i]]);
            int cnt = distance(ms2.begin(), ms2.lower_bound(pos2[nums1[i]]));  // O(N) worst case
            left[i] = cnt;
        }


        ms2.clear();
        ms2.insert(pos2[nums1[N-1]]);
        vector<int> right(N, 0);

        for (int i=N-2; i>=0; i--) {
            ms2.insert(pos2[nums1[i]]);
            int cnt = ms2.size()-1-distance(ms2.begin(), ms2.lower_bound(pos2[nums1[i]]));  // O(N) worst case
            right[i] = cnt;
        }

        long long res = 0;
        for (int i=0; i<N; i++) {
            res += (long long)left[i]*right[i];
        }

        return res;
    }
};




// segment tree solution
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

        int mid = (low + high) / 2;
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

        int mid = (low + high) >> 1;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return (left + right);
    }

    void update(int ind, int low, int high, int i, int val) {
        if (low == high) {
            seg[ind] = val;
            return;
        }

        int mid = (low + high) >> 1;
        if (i <= mid) update(2 * ind + 1, low, mid, i, val);
        else update(2 * ind + 2, mid + 1, high, i, val);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
};


class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int N = nums1.size();
        vector<int> pos2;

        for (int i=0; i<N; i++) {
            pos2[nums2[i]] = i;
        }

        SGTree* sgt = new SGTree(N);
        long long res = 0;

        for (int i=0; i<N; i++) {  // nums[i] is the middle point of some good triplets
            sgt->update(0, 0, N-1, pos2[nums1[i]], 1);
            int midPos = pos2[nums1[i]];
            int left = sgt->query(0, 0, N-1, 0, midPos) - 1;
            int right = (N - midPos-1) - sgt->query(0, 0, N-1, midPos+1, N-1);
            res += (long long)left*right;
        }

        return res;
    }
};


// BIT is faster
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


class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int N = nums1.size();
        vector<int> pos2(N);

        for (int i=0; i<N; i++) {
            pos2[nums2[i]] = i;
        }

        FenwickTree* FT = new FenwickTree(N); // fenwick tree for positions in nums2
        long long res = 0;

        for (int i=0; i<N; i++) {
            int midPos = pos2[nums1[i]]+1;  // note that BIT is 1-index
            FT->update(midPos, 1);          // mark the visited position to 1
            int left = FT->query(midPos-1); // calculate previous marked positions < midPos
            int right = (N-midPos) - FT->rangeQuery(midPos+1, N); // calculate positions > midPos without but not marked
            res += (long long)left*right;
        }

        return res;
    }
};
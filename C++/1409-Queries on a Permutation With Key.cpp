// O(n^2)
class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> res;
        deque<int> arr;
        for (int i=1; i<=m; i++) arr.push_back(i);

        for (int q:queries) {
            auto it = find(arr.begin(), arr.end(), q);
            res.push_back(it-arr.begin());
            arr.erase(it);
            arr.push_front(q);
        }

        return res;
    }
};


// smart BIT solution, create a BIT of size = 2*m
class BIT {
private:
    vector<int> tree; // Binary Indexed Tree
    int n;

public:
    // Constructor to initialize the Fenwick Tree with size `n`
    BIT(int size) : n(size) {
        tree.resize(n + 1, 0); // 1-based indexing
    }

    // Add value `delta` at index `idx` (1-based index)
    void update(int idx, int delta) {
        while (idx <= n) {
            tree[idx] += delta;
            idx += idx & -idx; // Move to the next index
        }
    }

    // Get the prefix sum from 1 to `idx` (1-based index)
    int query(int idx) const {
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
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
    vector<int> processQueries(vector<int>& queries, int m) {
        BIT tree(2*m+1);
        vector<int> pos(m+1); // map the position of number to the tree
        vector<int> res;

        for (int i=1; i<=m; i++) pos[i] = m+i;

        for (int i=1; i<=m; i++) tree.update(pos[i], 1);

        int candidatePos = m;

        for (int q:queries) {
            res.push_back(tree.query(pos[q])-1);
            tree.update(pos[q], -1);
            tree.update(candidatePos, 1);
            pos[q] = candidatePos;
            candidatePos--;
        }
        return res;

    }
};
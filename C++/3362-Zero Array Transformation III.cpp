// two priority queues
class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int N = nums.size(), Nq = queries.size();
        sort(begin(queries), end(queries));
        priority_queue<int> endPQ;   // store candidate end positions in the queries
        priority_queue<int, vector<int>, greater<>> chosen;  // store the end positions of  the chosen  queries
        int pqIdx = 0, used = 0;

        for (int i=0; i<N; i++) {
            while (pqIdx < Nq && i == queries[pqIdx][0]) {
                endPQ.push(queries[pqIdx][1]);
                pqIdx++;
            }
            nums[i] -= chosen.size();
            while (nums[i] > 0 && !endPQ.empty() && endPQ.top() >= i) {
                chosen.push(endPQ.top());
                endPQ.pop();
                nums[i]--;
                used++;
            }

            if (nums[i] > 0) return -1;
            while (!chosen.empty() && chosen.top() <= i) {
                chosen.pop();
            }
        }

        return Nq-used;
    }
};



// segment tree solution
class ST { // Segment tree class
public:
    vector<int> tree;
    vector<int> ltree; // Lazy tree for lazy propagation

    ST(int n) {
        tree.resize(4 * n);
        ltree.resize(4 * n, 0);
    }

    void build(int ind, int left, int right, vector<int>& nums) {
        if (left == right) {
            tree[ind] = nums[left]; // Leaf node stores nums[i]
            return;
        }
        int mid = left + (right-left) / 2;
        build(2 * ind + 1, left, mid, nums); // Recursive call
        build(2 * ind + 2, mid + 1, right, nums);
        tree[ind] = max(tree[2 * ind + 1], tree[2 * ind + 2]);
    }

    void propagate(int ind, int left, int right) { // Lazy propagation
        if (ltree[ind] != 0) {
            tree[ind] -= ltree[ind];
            if (left != right) {
                ltree[2 * ind + 1] += ltree[ind];
                ltree[2 * ind + 2] += ltree[ind];
            }
            ltree[ind] = 0;
        }
    }

    void update(int ind, int left, int right, int L, int R, int val) { // Update range [L, R]
        propagate(ind, left, right);
        if (R < left || L > right) return;
        if (L <= left && right <= R) {
            tree[ind] += val;
            if (left != right) {
                ltree[2 * ind + 1] -= val;
                ltree[2 * ind + 2] -= val;
            }
            return;
        }
        int mid = left + (right-left) / 2;
        update(2 * ind + 1, left, mid, L, R, val);
        update(2 * ind + 2, mid + 1, right, L, R, val);
        tree[ind] = max(tree[2 * ind + 1], tree[2 * ind + 2]);
    }

    int query(int ind, int left, int right, int L, int R) { // Get the value within [L, R]
        propagate(ind, left, right);

        // no overlap
        // L R left right or left right L R
        if (R < left || right < L) return 0;

        // complete overlap
        // [l low high r]
        if (left >= L && right <= R) return tree[ind];

        int mid = left + (right-left) / 2;
        int leftVal = query(2 * ind + 1, left, mid, L, R);
        int rightVal = query(2 * ind + 2, mid + 1, right, L, R);
        return (leftVal + rightVal);
    }
};

class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) { // cannot use auto here. sort() needs a comparator with a fixed type signature known at compile time.
        return a[0] < b[0];
    }
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int N = nums.size(), qIdx = 0, Nq = queries.size();
        ST st(N);
        st.build(0, 0, N-1, nums);
        sort(begin(queries), end(queries), cmp);
        priority_queue<int> pq;  // keep the end index of all queries
        int used = 0;

        for (int i=0; i<N; i++) {
            while (qIdx < Nq && i == queries[qIdx][0]) {
                pq.push(queries[qIdx][1]);
                qIdx++;
            }
            while (st.query(0, 0, N-1, i, i) > 0) {
                if (pq.empty() || pq.top() < i) return -1;
                int end = pq.top(); pq.pop();
                used++;
                st.update(0, 0, N-1, i, end, -1);
            }
        }

        return Nq-used;
    }
};
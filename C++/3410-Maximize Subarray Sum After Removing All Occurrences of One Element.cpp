using LL = long long;
class node {
public:
    LL tot = 0, preSum = 0, sufSum = 0, maxi = LLONG_MIN;
    node (){};
    node (LL val) {
        tot = preSum = sufSum = maxi = val;
    }
};

class SGTree {
    vector<node> seg;
public:
    SGTree(int n) {
        seg.resize(4 * n + 1, 0);
    }

    node merge(node &a, node& b) {
        node ans;
        ans.tot = a.tot + b.tot;
        ans.preSum = max(a.preSum, a.tot + b.preSum);
        ans.sufSum = max(b.sufSum, b.tot + a.sufSum);
        ans.maxi = max({a.maxi, b.maxi, a.sufSum + b.preSum});

        return ans;
    }

    void build(int ind, int low, int high, vector<int>& arr) {
        if (low == high) {
            seg[ind] = node(arr[low]);
            return;
        }

        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = merge(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    node query(int ind, int low, int high, int l, int r) {
        // no overlap
        // l r low high or low high l r
        if (r < low || high < l) return node(0);

        // complete overlap
        // [l low high r]
        if (low >= l && high <= r) return node(seg[ind]);

        int mid = (low + high) >> 1;
        node left = query(2 * ind + 1, low, mid, l, r);
        node right = query(2 * ind + 2, mid + 1, high, l, r);
        return merge(left, right);
    }

    void update(int ind, int low, int high, int i, int val) {
        if (low == high) {
            seg[ind] = node(val);
            return;
        }

        int mid = (low + high) >> 1;
        if (i <= mid) update(2 * ind + 1, low, mid, i, val);
        else update(2 * ind + 2, mid + 1, high, i, val);
        seg[ind] = merge(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};



class Solution {
public:
    long long maxSubarraySum(vector<int>& nums) {
        int N = nums.size(), negCnt = 0;
        unordered_map<int, vector<int>> hmap;
        
        SGTree sgt(N);
        sgt.build(0, 0, N-1, nums);

        for (int i=0; i<N; i++) {
            if (nums[i] < 0) {
                hmap[nums[i]].push_back(i);
                negCnt++;
            }
        }

        // Two cases that we don't need the operation
        if (negCnt == 0) {
            return accumulate(begin(nums), end(nums), 0LL);
        }
        if (negCnt == N) {
            return *max_element(begin(nums), end(nums));
        }

        LL res = LLONG_MIN;
        for (auto &[k, vec]:hmap) {
            if (vec.size() == N) continue;
            for (int v:vec) {
                sgt.update(0, 0, N-1, v, 0);
            }
            res = max(res, sgt.query(0, 0, N-1, 0, N-1).maxi);
            for (int v:vec) {
                sgt.update(0, 0, N-1, v, k);
            }
        }

        return res;
    }
};
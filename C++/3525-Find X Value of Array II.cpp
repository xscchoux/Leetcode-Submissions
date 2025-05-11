// https://leetcode.com/problems/find-x-value-of-array-ii/solutions/6669302/easy-understand-node-on-traditional-segment-tree-with-c-beat-90/
class Node {
public:
    int product, remainderCnt[5];
    Node() {
        product = 1;
        fill(remainderCnt, remainderCnt+5, 0);
    }
};

class SGTree {
    vector<Node> seg;
    int k;
public:
    SGTree(int n, int k) {
        seg.resize(4 * n + 1);
        this->k = k;
    }

    void build(int ind, int low, int high, vector<int>& arr) {
        if (low == high) {
            seg[ind].remainderCnt[arr[low]%k] = 1;
            seg[ind].product = arr[low]%k;
            return;
        }

        int mid = low + (high - low) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        // merge
        for (int kk=0; kk<k; kk++) {
            seg[ind].remainderCnt[kk] = seg[2*ind+1].remainderCnt[kk];
        }
        for (int rightRemainder=0; rightRemainder<k; rightRemainder++) {
            int newRemainder = (rightRemainder*seg[2*ind+1].product)%k;
            seg[ind].remainderCnt[newRemainder] += seg[2*ind+2].remainderCnt[rightRemainder]; 
        }
        seg[ind].product = (seg[2*ind+1].product*seg[2*ind+2].product)%k;
    }

    Node query(int ind, int low, int high, int l, int r) {
        // no overlap
        // l r low high or low high l r
        if (r < low || high < l) return Node();

        // complete overlap
        // [l low high r]
        if (low >= l && high <= r) return seg[ind];

        int mid = low + (high - low) / 2;
        Node leftNode = query(2 * ind + 1, low, mid, l, r);
        Node rightNode = query(2 * ind + 2, mid + 1, high, l, r);

        Node curr = Node();
        // merge
        for (int kk=0; kk<k; kk++) {
            curr.remainderCnt[kk] = leftNode.remainderCnt[kk];
        }
        for (int rightRemainder=0; rightRemainder<k; rightRemainder++) {
            int newRemainder = (rightRemainder*leftNode.product)%k;
            curr.remainderCnt[newRemainder] += rightNode.remainderCnt[rightRemainder]; 
        }
        curr.product = (leftNode.product*rightNode.product)%k;
        return curr;
    }

    void update(int ind, int low, int high, int i, int val) {
        if (low == high) {
            for (int kk=0; kk<k; kk++) seg[ind].remainderCnt[kk] = 0;
            seg[ind].remainderCnt[val%k] = 1;
            seg[ind].product = val%k;
            return;
        }

        int mid = low + (high - low) / 2;
        if (i <= mid) update(2 * ind + 1, low, mid, i, val);
        else update(2 * ind + 2, mid + 1, high, i, val);

        // merge
        for (int kk=0; kk<k; kk++) {
            seg[ind].remainderCnt[kk] = seg[2*ind+1].remainderCnt[kk];
        }
        for (int rightRemainder=0; rightRemainder<k; rightRemainder++) {
            int newRemainder = (rightRemainder*seg[2*ind+1].product)%k;
            seg[ind].remainderCnt[newRemainder] += seg[2*ind+2].remainderCnt[rightRemainder]; 
        }
        seg[ind].product = (seg[2*ind+1].product*seg[2*ind+2].product)%k;
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int N = nums.size();
        SGTree sgt(N, k);
        sgt.build(0, 0, N-1, nums);
        vector<int> res;

        for (auto &q:queries) {
            int index = q[0], value = q[1], start = q[2], x = q[3];

            sgt.update(0, 0, N-1, index, value);

            res.push_back(sgt.query(0, 0, N-1, start, N-1).remainderCnt[x]);
        }

        return res;
    }
};
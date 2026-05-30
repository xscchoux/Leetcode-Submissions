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
		return max(left, right);
	}

	void update(int ind, int low, int high, int i, int val) {
		if (low == high) {
			seg[ind] = val;
			return;
		}

		int mid = low + (high - low) / 2;
		if (i <= mid) update(2 * ind + 1, low, mid, i, val);
		else update(2 * ind + 2, mid + 1, high, i, val);
		seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
	}
};


class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int mx = 5e4;
        SGTree sgt(mx+1);
        set<int> s;
        s.insert(0);
        s.insert(mx+1);
        vector<bool> res;

        // store segment length at the end (block) of each segment in the segment tree
        for (auto &q:queries) {
            if (q[0] == 1) {
                int pos = q[1];  //  Note that it is guaranteed that there is no obstacle at distance x when the query is asked
                auto rightBound = s.upper_bound(pos);
                auto leftBound = prev(rightBound);
                int rightPos = *rightBound;
                int leftPos = *leftBound;
                sgt.update(0, 0, mx+1, pos, pos-leftPos);
                sgt.update(0, 0, mx+1, rightPos, rightPos-pos);
                s.insert(pos);
            } else {
                int pos = q[1], sz = q[2];
                auto rightBound = s.lower_bound(pos);
                auto pre = prev(rightBound);

                int blank = pos-*pre;
                if (*pre != 0) {
                    blank = max(blank, sgt.query(0, 0, mx+1, 0, *pre));
                }
                res.push_back(blank >= sz);
            }
        }

        return res;
    }
};
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
			seg[ind] += val;
			return;
		}

		int mid = low + (high - low) / 2;
		if (i <= mid) update(2 * ind + 1, low, mid, i, val);
		else update(2 * ind + 2, mid + 1, high, i, val);
		seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
	}
};


class Solution {
public:
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        // y*a - x*b >= 0, each even num gives -b, and each odd num gives a
        int N = nums.size();

        vector<long long> vals = {0};   // note that we need to give zero when there's no number
        long long curr = 0;

        for (int i=0; i<N; i++) {
            if (nums[i]%2) {
                curr += a;
            } else {
                curr -= b;
            }
            vals.push_back(curr);
        }     

        set<long long> s;
        for (long long v:vals) {
            s.insert(v);
        }

        int sLen = s.size();
        SGTree sgt(sLen);

        // coordinate compression
        unordered_map<long long, int> rank; // value:index
        
        int idx = 0;
        for (int num:s) {
            rank[num] = idx;
            idx++;
        }

        long long res = 0;

        for (int i=0; i<vals.size(); i++) {
            int v = vals[i];
            int idx = rank[v];
            res += sgt.query(0, 0, sLen-1, 0, idx);
            sgt.update(0, 0, sLen-1, idx, 1);
        }


        return res;

    }
};
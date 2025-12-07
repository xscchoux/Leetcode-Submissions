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
    long long minInversionCount(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int> tmp = nums;
        sort(begin(tmp), end(tmp));
        unordered_map<int, int> mapping;

        int curr = 1;
        for (int i=0; i<N; i++) {
            if (i > 0 && tmp[i] > tmp[i-1]) {
                curr++;
                mapping[tmp[i]] = curr;
            } else {
                mapping[tmp[i]] = curr;
            }
        }

        for (int i=0; i<N; i++) {
            nums[i] = mapping[nums[i]];
        }

        SGTree sgt(N+1);
        long long res = LLONG_MAX, cnt = 0;

        for (int i=0; i<N; i++) {
            // update segment tree
            sgt.update(0, 0, N, nums[i], 1);
            
            // update count
            cnt += sgt.query(0, 0, N, nums[i]+1, N);
            
            if (i >= k-1) {
                res = min(res, cnt);
            }

            // remove
            if (i-k+1 >= 0) {
                cnt -= sgt.query(0, 0, N, 0, nums[i-k+1]-1);
                sgt.update(0, 0, N, nums[i-k+1], -1);
            }
        }

        return res;
    }
};
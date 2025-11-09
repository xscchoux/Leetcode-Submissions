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

	void add(int ind, int low, int high, int i, int val) {
		if (low == high) {
			seg[ind] += val;  // made a little change here
			return;
		}

		int mid = low + (high - low) / 2;
		if (i <= mid) add(2 * ind + 1, low, mid, i, val);
		else add(2 * ind + 2, mid + 1, high, i, val);
		seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
	}
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int N = nums.size();

        SGTree sgt(2*N+1);
        sgt.add(0, 0, 2*N+1, N, 1);

        int preSum = 0;
        long long res = 0;
        for (int i=0; i<N; i++) {
            preSum += (target == nums[i]?1:-1);
            res += sgt.query(0, 0, 2*N+1, 0, preSum+N-1);
            sgt.add(0, 0, 2*N+1, preSum+N, 1);
        }

        return res;
    }
};
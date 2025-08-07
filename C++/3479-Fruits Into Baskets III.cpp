// O(n^(3/2)), square root decomposition
// https://leetcode.com/problems/fruits-into-baskets-iii/editorial/
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int N = baskets.size(), blockLen = sqrt(N);
        int blockCnt = (N+blockLen-1)/blockLen;
        vector<int> maxV(blockCnt);

        for (int i=0; i<N; i++) {
            maxV[i/blockLen] = max(maxV[i/blockLen], baskets[i]);
        }

        int res = 0;

        for (int fruit:fruits) {
            bool picked = false;
            for (int block=0; block < blockCnt; block++) {
                if (maxV[block] < fruit) continue;
                maxV[block] = 0;
                for (int i=0; i<blockLen; i++) {
                    int idx = block*blockLen + i;
                    if (idx < N && baskets[idx] >= fruit && !picked) {
                        baskets[idx] = 0;
                        picked = true;
                    }
                    if (idx < N) {
                        maxV[block] = max(maxV[block], baskets[idx]);
                    }
                }
                if (picked) {
                    break;
                }
            }
            if (!picked) res++;
        }

        return res;
    }
};


// O(N*logN*logN)
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
		seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
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
		return max(left, right);
	}

	void update(int ind, int low, int high, int i, int val) {
		if (low == high) {
			seg[ind] = val;
			return;
		}

		int mid = (low + high) >> 1;
		if (i <= mid) update(2 * ind + 1, low, mid, i, val);
		else update(2 * ind + 2, mid + 1, high, i, val);
		seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
	}
};

class Solution {
public:
    int N;
    int find(int curr, SGTree& sgt) {
        int left = 0, right = N-1, res = 0;
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            int maxVal = sgt.query(0, 0, N-1, 0, mid);  // finding max value in the range 0 to mid
            if (maxVal >= curr) {
                right = mid;
            } else {
                left = mid;
            }
        }

        if (sgt.query(0, 0, N-1, 0, right) < curr) {
            return 1;
        }

        int idxChanged;
        if (sgt.query(0, 0, N-1, 0, left) >= curr) {
            idxChanged = left;
        } else {
            idxChanged = right;
        }

        sgt.update(0, 0, N-1, idxChanged, 0);
        return 0;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        this->N = baskets.size();
        SGTree sgt(N);
        sgt.build(0, 0, N-1, baskets);
        int res = 0;

        for (int i=0; i<N; i++) {
            res += find(fruits[i], sgt);
        }

        return res;
    }
};
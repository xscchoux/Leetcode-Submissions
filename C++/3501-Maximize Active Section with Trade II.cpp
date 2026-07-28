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
		seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
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
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int N = s.size();

        vector<int> zeroBlock, blockLeft, blockRight;

        int idx = 0;

        while (idx < N) {
            int curr = s[idx], i = idx;
            while (i<N && s[i] == s[idx]) {
                i++;
            }

            if (curr == '0') {
                zeroBlock.push_back(i-idx);
                blockLeft.push_back(idx);
                blockRight.push_back(i-1);
            }
            idx = i;
        }

        int totalOne = 0;
        for (int i=0; i<N; i++) {
            if (s[i] == '1') totalOne++;
        }

        if (zeroBlock.size() < 2) {
            return vector<int>(queries.size(), totalOne);
        }
        
        int Nblock = zeroBlock.size();
        vector<int> twoSum;
        for (int i=0; i<Nblock-1; i++) {
            twoSum.push_back(zeroBlock[i] + zeroBlock[i+1]);
        }

        SGTree sgt(Nblock-1);
        sgt.build(0, 0, Nblock-2, twoSum);
        
        vector<int> res;

        for (auto &q:queries) {
            int l = q[0], r = q[1];
            int leftIdx = lower_bound(begin(blockRight), end(blockRight), l) - begin(blockRight);
            int rightIdx = upper_bound(begin(blockLeft), end(blockLeft), r) - begin(blockLeft) - 1;

            if (leftIdx >= rightIdx) {
                res.push_back(totalOne);
                continue;
            }

            int leftPart = blockRight[leftIdx] - max(blockLeft[leftIdx], l) + 1;
            int rightPart = min(r, blockRight[rightIdx]) - blockLeft[rightIdx] + 1;

            if (leftIdx + 1 == rightIdx) {
                res.push_back(totalOne + leftPart + rightPart);
                continue;
            }

            int leftMost = leftPart + zeroBlock[leftIdx+1];
            // leftIdx+1 ~ rightIdx-2 in twoSum
            int middle = sgt.query(0, 0, Nblock-2, leftIdx+1, rightIdx-2);
            int rightMost = rightPart + zeroBlock[rightIdx-1];

            res.push_back(totalOne + max({leftMost, middle, rightMost}));
        }
        
        return res;
    }
};
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
    vector<int> minDeletions(string s, vector<vector<int>>& queries) {
        int N = s.size();
        vector<int> arr(N, 0);


        // Define arr[i] = 1 if i >= 1 and s[i] == s[i - 1], otherwise arr[i] = 0, very tricky
        for (int i=1; i<N; i++) {
            if (s[i] == s[i-1]) {
                arr[i]++;
            }
        }

        SGTree sgt(N);
        sgt.build(0, 0, N-1, arr);
        vector<int> res;

        for (auto &q:queries) {
            int flag = q[0];
            if (flag == 1) {
                int i = q[1];
                if (i > 0 && s[i-1] == s[i]) {
                    sgt.update(0, 0, N-1, i, -1);
                }
                if (i > 0 && s[i-1] != s[i]) {
                    sgt.update(0, 0, N-1, i, 1);
                }
                if (i+1 <= N-1 && s[i] != s[i+1]) {
                    sgt.update(0, 0, N-1, i+1, 1);                    
                }
                if (i+1 <= N-1 && s[i] == s[i+1]) {
                    sgt.update(0, 0, N-1, i+1, -1);                    
                }
                s[i] = (s[i]=='A')?'B':'A';
            } else {
                int left = q[1], right = q[2];
                int pairs = 0;
                if (left != right) {
                    pairs = sgt.query(0, 0, N-1, left+1, right);
                }
                res.push_back(pairs);
            }
        }

        return res;
    }
};
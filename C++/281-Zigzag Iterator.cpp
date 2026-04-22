class ZigzagIterator {
public:
    queue<pair<int, vector<int>&>> q;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (v1.size() > 0) q.push({0, v1});
        if (v2.size() > 0) q.push({0, v2});
    }

    int next() {
        int res = 0;
        if (!q.empty()) {
            auto [idx, v] = q.front();
            q.pop();
            res = v[idx];
            int nxtIdx = idx+1;
            if (nxtIdx < v.size()) {
                q.push({nxtIdx, v});
            }
        }
        return res;
    }

    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {
        map<int, set<int>> xMap, yMap;
        int rightMost = INT_MIN, upperMost = INT_MIN, leftMost = INT_MAX, lowerMost = INT_MAX;
        long long res = -1;
        for (auto &c:coords) {
            int x = c[0], y = c[1];
            xMap[x].insert(y);
            yMap[y].insert(x);
            rightMost = max(rightMost, x);
            leftMost = min(leftMost, x);
            upperMost = max(upperMost, y);
            lowerMost = min(lowerMost, y);
        }

        for (auto &[k, v]:xMap) {
            if (v.size() < 2) continue;
            int height = -1;
            if (rightMost != k) height = max(height, rightMost-k);
            if (leftMost != k) height = max(height, k-leftMost);
            if (height == -1) continue;
            int base = *prev(end(v)) - *begin(v);
            res = max(res, (long long)base*height);
        }

        for (auto &[k, v]:yMap) {
            if (v.size() < 2) continue;
            int height = -1;
            if (upperMost != k) height = max(height, upperMost-k);
            if (lowerMost != k) height = max(height, k-lowerMost);
            if (height == -1) continue;
            int base = *prev(end(v)) - *begin(v);
            res = max(res, (long long)base*height);
        }

        return res;
    }
};